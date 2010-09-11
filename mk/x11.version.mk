# $NetBSD: x11.version.mk,v 1.11 2010/09/11 20:46:11 wiz Exp $
#
# This file must not be included directly.
# It is included automatically by mk/x11.buildlink3.mk.
#
# User-settable variables:
#
# X11_TYPE
#	The X11 distribution that is used for building X11 packages.
#
#	Possible:
#	* native: use the native X11 distribution
#	* modular: use modular Xorg from pkgsrc
#
#	Default: native, unless defined for a specific operating system
#	in mk/platform/${OPSYS}.mk.
#
# Variables provided by this file:
#
# X11_PKGSRCDIR.${X11_TYPE}
#	The directory where the buildlink3.mk or builtin.mk files can
#	be found for the X11 distribution.
#
# BUILTIN_X11_TYPE.${X11_TYPE}
#	The X11_TYPE of the native X11 distribution detected on the
#	system.
#
# Variables that _may_ be defined by this file.  These variables
# should be checked to exist before they are used:
#
# BUILTIN_X11_VERSION.${X11_TYPE}
#	The version number of the native X11 distribution detected on
#	the system.
#

_VARGROUPS+=	x11
_USER_VARS.x11=	X11_TYPE X11BASE
_PKG_VARS.x11=	USE_X11BASE
_SYS_VARS.x11=	X11_PKGSRCDIR.${X11_TYPE} BUILTIN_X11_TYPE.${X11_TYPE} BUILTIN_X11_VERSION.${X11_TYPE}

X11_PKGSRCDIR.native=	../../pkgtools/x11-links

.include "${X11_PKGSRCDIR.${X11_TYPE}}/version.mk"
