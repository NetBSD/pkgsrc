# $NetBSD: shlib-som.awk,v 1.2 2007/04/21 14:15:59 tnn Exp $
#
###
### PLIST shlib filter for Spectrum Object Module format, SOM, on HP-UX.
###

# XXX: Nothing here yet. Libtoolized packages don't need any special attention,
# but for others we need to manually deal with the .sl library suffix.
/.*\/lib[^\/]+\.so(\.[0-9]+)*$/ {
	sub("\.so$", ".sl");
	sub("\.so\.", ".sl.");
}
{
	print
}
