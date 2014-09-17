#!/usr/bin/awk -f
BEGIN {
	cur_fixed = 0
	cur_variable = 0
}

/^#/	{ next }
/^[[:space:]]*$/	{ next }
{
	if ($2 == "") {
		f = "transform_pass"
		a = "NULL"
		if (NF > 1) {
			print "Too many fields for pass rule"
			exit 1
		}
	} else if ($2 == "==>") {
		f = "transform_replace"
		a = "\"" $3 "\""
		if (a == "") {
			print "Missing argument in line ", FNR
			exit 1
		}
		if (NF > 3) {
			print "Too many fields for replace rule"
			exit 1
		}
	} else if ($2 == "==!") {
		f = "transform_pass_with_warning"
		a = "NULL"
		if (NF > 2) {
			print "Too many fields for warning rule"
			exit 1
		}
	} else if ($2 == "==|") {
		f = "transform_discard"
		a = "NULL"
		if (NF > 2) {
			print "Too many fields for discard rule"
			exit 1
		}
	} else {
		print "Unsupported transformation type"
		exit 1
	}
	
	if ($1 ~ /\*$/) {
		$1 = substr($1, 1, length($1) - 1)
		variable_transforms[cur_variable++] = \
		    sprintf("{ \"%s\", %d, %s, %s }", $1, length($1), f, a)
	} else {
		fixed_transforms[cur_fixed] = \
		    sprintf("{ \"%s\", %d, %s, %s }", $1, length($1), f, a)
		fixed_keys[cur_fixed++] = $1
	}
}

END {
	print ARGV[1]

	ruleset = ARGV[1]
	fname = "transform_cc_fixed"
	output_c1 = ruleset "-fixed1.c"
	output_c2 = ruleset "-fixed2.c"
	output_c = ruleset "-fixed.c"
	output_map = ruleset "-fixed.map"
	nbperf = sprintf("nbperf -s -n %s -a chm -o %s -m %s",
	    fname, output_c1, output_map)
	for (i = 0; i < cur_fixed; ++i)
		print fixed_keys[i] | nbperf
	close(nbperf)
	for (i = 0; i < cur_fixed; ++i) {
		getline out < output_map
		fixed_order[out] = i
	}
	close(output_map)

	print "" > output_c2
	print "static struct transformation fixed_transforms[] = {" > output_c2
	for (i = 0; i < cur_fixed; ++i) {
		j = fixed_order[i]
		print "\t" fixed_transforms[j] "," > output_c2
	}
	print "};" > output_c2
	print "" > output_c2
	print "static struct transformation var_transforms[] = {" > output_c2
	for (i = 0; i < cur_variable; ++i) {
		print "\t" variable_transforms[i] "," > output_c2
	}
	print "\t{ NULL, 0, NULL, NULL }," > output_c2
	print "};" > output_c2
	close(output_c2)
	system(sprintf("cat %s %s > %s", output_c1, output_c2, output))
}
