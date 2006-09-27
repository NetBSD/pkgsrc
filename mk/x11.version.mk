# $NetBSD: x11.version.mk,v 1.5 2006/09/27 15:18:15 joerg Exp $
#
# The following variables may be set in /etc/mk.conf:
#
#    X11_TYPE sets the X11 distribution used when building X11 packages.
#	Possible values are "xorg" (use x11/xorg-libs), or "native"
#	(use the native X11 distribution).
#	The default X11_TYPE is "native" unless defined for a specific
#	operating system in mk/platform/${OPSYS}.mk.
#
# The following variables are provided by this file:
#
#    X11_PKGSRCDIR.${X11_TYPE} sets the pkgsrc directory location for
#	the package which manages/represents ${X11_TYPE}.  It can be
#	used to find the relevant buildlink3.mk or builtin.mk files.
#
#    BUILTIN_X11_TYPE.${X11_TYPE} is the X11_TYPE of the native X11
#	distribution detected on the system.
#
# The following variables may be defined by this file.  These variables
# should be checked to exist before they are used:
#
#    BUILTIN_X11_VERSION.${X11_TYPE} is the version number of the native
#	X11 distribution detected on the system.
#

X11_PKGSRCDIR.native=	../../pkgtools/x11-links
X11_PKGSRCDIR.xorg=	../../x11/xorg-libs

# Makefiles that include this file can access the version of the X11
# distribution as ${BUILTIN_X11_VERSION.${X11_TYPE}}.
#
.sinclude "${X11_PKGSRCDIR.${X11_TYPE}}/version.mk"
