# $NetBSD: check-pie-elf.awk,v 1.1 2022/01/18 01:41:09 pho Exp $
#
# Read a list of potential ELF binaries from stdin. For each, extract the list
# of headers. There are four possibilities:
#
# 1. Elf_Ehdr.e_type == ET_EXEC &&
#    PT_INTERP does not exist
#
#	This is a statically-linked executable. Ignore these, as they cannot
#	ever be a PIE.
#
# 2. Elf_Ehdr.e_type == ET_EXEC &&
#    PT_INTERP exists in the program headers
#
#	This is a dynamically-linked non-PIE that this script complains about.
#
# 3. Elf_Ehdr.e_type == ET_DYN &&
#    PT_INTERP exists in the program headers &&
#    DT_FLAGS_1 exists in the dynamic section &&
#    DT_FLAGS_1 contains DF_1_PIE
#
#	This is a PIE.
#
# 4. Elf_Ehdr.e_type == ET_DYN &&
#    PT_INTERP does not exist in the program headers
#
#	This is a shared object.
#
# See also https://stackoverflow.com/a/55704865
#

function shquote(IN, out) {
	out = IN;
	gsub("\\\\", "\\\\", out);
	gsub("\\\n", "\\n", out);
	gsub("\\\t", "\\t", out);
	gsub(" ", "\\ ", out);
	gsub("'", "\\'", out);
	gsub("`", "\\`", out);
	gsub("\"", "\\\"", out);
	gsub(";", "\\;", out);
	gsub("&", "\\&", out);
	gsub("<", "\\<", out);
	gsub(">", "\\>", out);
	gsub("\\(", "\\(", out);
	gsub("\\)", "\\)", out);
	gsub("\\|", "\\|", out);
	gsub("\\*", "\\*", out);
	gsub("\\?", "\\?", out);
	gsub("\\{", "\\{", out);
	gsub("\\}", "\\}", out);
	gsub("\\[", "\\[", out);
	gsub("\\]", "\\]", out);
	gsub("\\$", "\\$", out);
	gsub("!", "\\!", out);
	gsub("#", "\\#", out);
	gsub("\\^", "\\^", out);
	gsub("~", "\\~", out);
	return out;
}

function check_pie(ELF, is_non_pie, is_dyn_exec) {
	is_non_pie = 0;
	is_dyn_exec = 0;
	cmd = readelf " -Whl " shquote(ELF) " 2>/dev/null";
	while ((cmd | getline) > 0) {
		if ($1 == "Type:" && $2 == "EXEC") {
			is_non_pie = 1;
		}
		else if ($1 == "INTERP") {
			is_dyn_exec = 1;
		}
	}
	close(cmd);
	if (is_non_pie == 1 && is_dyn_exec == 1) {
		print ELF ": not a PIE";
	}
}

BEGIN {
	readelf = ENVIRON["READELF"];
	if (readelf == "") {
		readelf = "readelf";
	}
}

{ check_pie($0); }
