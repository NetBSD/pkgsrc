BEGIN { process = 1 }

/NBCOMPAT template section follows\./ { process = 0 }

/^\#[ 	]*define[ 	]+PACKAGE_.*/ {
	if (process == 0)
		next;
	print "/* " $0 " */";
	next;
}

/^\#[ 	]*define[ 	]+/ {
	if (process == 0)
		next;
	guard = $0;
	sub("^#[ 	]*define[ 	]+", "", guard);
	sub("[ 	]+.*", "", guard);
	print "#ifndef " guard;
	print $0;
	print "#endif";
	next;
}

{ print }
