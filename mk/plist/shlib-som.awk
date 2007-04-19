# $NetBSD: shlib-som.awk,v 1.1 2007/04/19 23:13:42 tnn Exp $
#
###
### PLIST shlib filter for Spectrum Object Module format, SOM, on HP-UX.
###

# XXX: Nothing here yet. Libtoolized packages don't need any special attention,
# but for others we need to manually deal with the .sl library suffix.
{
	print
}
