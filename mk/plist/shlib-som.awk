# $NetBSD: shlib-som.awk,v 1.3 2007/04/22 19:54:44 tnn Exp $
#
###
### PLIST shlib filter for Spectrum Object Module format, SOM, on HP-UX.
###

# Libtoolized packages don't need any special attention, but for others we need
# to manually deal with the .sl library suffix.

# Match shared libs
/.*\/lib[^\/]+\.so(\.[0-9]+)*$/ {
	sub("\.so\.", ".sl.");
}
# Match dynamically loaded modules
/.*\.so$/ {
	sub("\.so$", ".sl");
}
{
	print
}
