# Copyright (c) 2010, Aleksey Cheusov <vle@gmx.net>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
#       copyright notice, this list of conditions and the following
#       disclaimer in the documentation and/or other materials provided
#       with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#use "has_prefix.awk"
#use "has_suffix.awk"
#use "psu_funcs.awk"

#env "LC_ALL=C"

BEGIN {
	if (ic)
		string = tolower(string)

	_gs_matched = -1 # -1 - unknown, 0 - false, 1 - true
	_gs_count   = 0

	_sg_multiline ["PLIST"]       = 1
	_sg_multiline ["DESCRIPTION"] = 1
	_sg_multiline ["DEPENDS"]     = 1
	_sg_multiline ["REQUIRES"]    = 1
	_sg_multiline ["PROVIDES"]    = 1
	_sg_multiline ["CONFLICTS"]   = 1

	keep_fields = 0

	invert += 0

	# required fields
	gsub(/,/, " ", reqd_fields_)
	reqd_fields_cnt = split(reqd_fields_, f)
	for (i=1; i <= reqd_fields_cnt; ++i){
		reqd_fields [f [i]] = 1
	}
	delete f
}

function match_first_word (s, word){
	if (s == word)
		return 1
	else if (!has_prefix(s, word))
		return 0
	else{
		return substr(s, length(word)+1, 1) ~ /^[^A-Za-z0-9]$/
	}
}

function match_last_word (s, word){
	if (s == word)
		return 1
	else if (!has_suffix(s, word))
		return 0
	else
		return substr(s, length(s)-length(word), 1) ~ /^[^A-Za-z0-9]$/
}

function match_word (s, word,                  idx){
	if (s == word)
		return 1

	idx = index(s, word)
	if (!idx)
		return 0

	if (idx > 1 && substr(s, idx-1, 1) ~ /[A-Za-z0-9]$/)
		return 0

	idx += length(word)
	if (idx <= length(s) && substr(s, idx, 1) ~ /[A-Za-z0-9]$/)
		return 0

	return 1
}

function match_keywords (s,         cnt_s, arr_s, set_s, i){
    if (s !~ re_kw)
		return 0

	cnt_s = split(s, arr_s, /[^A-Za-z0-9]/)
	for (i=1; i <= cnt_s; ++i){
		set_s [arr_s [i]] = 1
	}

	for (i=1; i <= cnt_kw; ++i){
		if (! (arr_kw [i] in set_s)){
			return 0
		}
	}

	return 1
}

function update_skip (){
	if (ic)
		fvalue = tolower(fvalue)

	_gs_matched = grep_summary__condition()

	if (_gs_matched == 0 && (fname in _sg_multiline)){
		_gs_matched = -1
	}

	if (invert && _gs_matched >= 0){
		_gs_matched = 1-_gs_matched;
	}

	if (_gs_matched == 1){
		for (i=0; i < _gs_count; ++i)
			print _gs_accu [i]

		delete _gs_accu
		_gs_count = 0
	}
}

_gs_matched == 0 && NF > 0 {
	next
}

{
	pos = index($0, "=")
	if (pos > 0){
		fname  = substr($0, 1, pos-1)
		fvalue = substr($0, pos+1)
	}else{
		fname  = ""
		fvalue = ""
	}
	fname_orig = fname
}

function check_PKGPATHe (){
	if (_gs_assigns != "" && _gs_pkgpath != ""){
		fvalue = _gs_pkgpath ":" _gs_assigns
		fname  = "PKGPATHe"
		update_skip()
	}else if (index(_gs_pkgpath, ":") > 0){
		fvalue = _gs_pkgpath
		fname  = "PKGPATHe"
		update_skip()
	}
}

_gs_matched == -1 {
	if (grep_summary__field == "PKGBASE"){
		if (fname == "PKGNAME"){
			fname = "PKGBASE"
			fvalue = pkgname2pkgbase(fvalue)
			update_skip()
		}
	}else if (grep_summary__field == "PKGPATHe"){
		if (fname == "ASSIGNMENTS") {
			_gs_assigns = fvalue
			check_PKGPATHe()
		}else if (fname == "PKGPATH") {
			_gs_pkgpath = fvalue
			check_PKGPATHe()
		}
	}else if (grep_summary__field == "PKGPATH"){
		idx = index(fvalue, ":")
		if (idx > 0)
			fvalue = substr(fvalue, 1, idx-1)
	}else if (grep_summary__field == "PKGPAIR" ||
		      grep_summary__field == "PKGPABA" ||
		      grep_summary__field == "PKGPANA")
	{
		if (fname == "PKGPATH") {
			_gs_pkgpath = fvalue
		}else if (fname == "PKGNAME") {
			_gs_pkgbase = fvalue
			if (grep_summary__field != "PKGPANA")
				sub(/-[^-]*$/, "", _gs_pkgbase)
		}

		if (_gs_pkgbase != "" && _gs_pkgpath != ""){
			fvalue = _gs_pkgpath "," _gs_pkgbase
			fname  = grep_summary__field
			update_skip()
		}
	}

	if (fname == grep_summary__field || "" == grep_summary__field) {
		update_skip()
	}
}

_gs_matched == 1 && NF > 0 {
	if (!reqd_fields_cnt || (fname_orig in reqd_fields))
		print $0

	next
}

keep_fields {
	fields [fname] = fvalue
}

_gs_matched == -1 && NF > 0 {
	if (!reqd_fields_cnt || (fname_orig in reqd_fields))
		_gs_accu [_gs_count++] = $0
}

NF == 0 {
	if (_gs_matched == -1 && grep_summary__field == "PKGPATHe"){
		fvalue = _gs_pkgpath
		update_skip()
		fvalue = ""
	}
	if (_gs_matched == -1){
		update_skip()
	}
	if (_gs_matched == 1){
		++_gs_matches_cnt
		print ""
	}

	delete _gs_accu
	delete fields
	_gs_count = 0
	_gs_matched = -1

	_gs_assigns = _gs_pkgpath = _gs_pkgbase = ""
}

END {
	if (error && !_gs_matches_cnt){
		if (error_msg)
			print error_msg > "/dev/stderr"

		exitnow(1)
	}
}
