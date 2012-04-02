# $NetBSD: hacks.mk,v 1.1 2012/04/02 04:02:46 dholland Exp $

# Apparently, what was ambitiously called "vala-1.0.pc" in some early release was
# later retconned to "vala-0.10.pc", and thus now 0.12.
#
# Also, this package runs "valac" as "valac" rather than as "valac-0.12".

post-wrapper:
	ln -s ${LOCALBASE}/lib/pkgconfig/libvala-0.12.pc ${BUILDLINK_DIR}/lib/pkgconfig/vala-1.0.pc
	ln -s ${VALAC} ${BUILDLINK_DIR}/bin/valac
