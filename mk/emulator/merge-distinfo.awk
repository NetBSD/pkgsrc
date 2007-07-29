# $NetBSD: merge-distinfo.awk,v 1.1 2007/07/29 05:19:43 jlam Exp $
#
# This awk script sorts the contents of several distinfo files into a
# single distinfo file.
#

# insertion sort
function sort(a, nelem,   temp, i, j) {
	for (i = 2; i <= nelem; ++i) {
		for (j = i; a[j-1] > a[j]; --j) {
			temp = a[j]
			a[j] = a[j-1]
			a[j-1] = temp
		}
	}
	return
}

/^[A-Z]+/ { 
	file = $2
	files[file] = file
	if (!($0 in seen)) {
		seen[$0] = $0
		properties[file, 0]++
		properties[file, properties[file, 0]] = $0
	}
}

END {
	print "$" "NetBSD" "$"
	print ""
	n = 1
	for (f in files) {
		orderedfiles[n++] = f
	}
	n--;
	sort(orderedfiles, n)
	for (i = 1; i <= n; i++) {
		f = orderedfiles[i]
		for (j = 1; j <= properties[f, 0]; j++)
			print properties[f, j]
	}
}
