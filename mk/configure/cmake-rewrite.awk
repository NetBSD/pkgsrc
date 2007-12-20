# $NetBSD: cmake-rewrite.awk,v 1.2 2007/12/20 18:51:18 abs Exp $
#
# cleanup references to libraries in the buildlink tree in files
# written by cmake's  export_library_dependencies() function
#
BEGIN { buildlink_dir = ARGV[1]; delete ARGV[1] }
{ 
    match($0, "_LIB_DEPENDS \"")
    if (RSTART == 0) {
	print
    } else {
	printf "%s \"", $1
	d=substr($0,RSTART+RLENGTH,length($0))
	while ( d != "\")") {
	    match(d,"[^;]*")
	    dep=substr(d,RSTART,RLENGTH)
	    d=substr(d,RLENGTH+2,length(d))
	    if (dep ~ "^" buildlink_dir) {
		"ls -l " dep | getline  ls_out
		close ("ls -l " dep)
		match(ls_out,"-> ")
		if (RSTART > 0) {
		    dep=substr(ls_out,RSTART+RLENGTH,length(ls_out))
		}
	    }
	    printf "%s;",dep
	}
	print d
    }
}
