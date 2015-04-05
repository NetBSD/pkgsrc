# $NetBSD: gen_matypes.awk,v 1.1 2015/04/05 17:01:37 tnn Exp $

BEGIN {
	while (getline) {
		if (/int main/) break;
	}
}

/printf/ {
	printf("printf %s\n", substr($0, 12, length($0) - 14))
}
/OFFSET\(/ {
	split(substr($0,12, length($0) - 14), offsets, ",");
	printf("offset %s \"%s\" \"%s\"\n", offsets[1], offsets[2], offsets[3]);
}
/OFFSET_HEADER/ {
	printf("offset_header %s\n", substr($0,19, length($0) - 21))
}

/DEFINE\(/ {
	split(substr($0,12, length($0) - 14), offsets, ",");
	printf("define %s \"%s\"\n", offsets[1], offsets[2]);
}
/DEFINE_HEADER/ {
	printf("define_header %s\n", substr($0,19, length($0) - 21))
}

/SIZEOF\(/ {
	split(substr($0,12, length($0) - 14), offsets, ",");
	printf("sizeof %s \"%s\"\n", offsets[1], offsets[2]);
}
