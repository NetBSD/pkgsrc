# $NetBSD: xaw.buildlink3.mk,v 1.7 2015/10/14 20:17:27 wiz Exp $
#
# This file selects the X Athena Widgets (Xaw) implementation.
#
# User-settable variables:
#
# XAW_TYPE
#	The Xaw type to be selected.
#
#	Possible: 3d neXtaw standard xpm
#	Default: standard
#

.if !defined(XAW_BUILDLINK3_MK)
XAW_BUILDLINK3_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		XAW_TYPE

.if ${XAW_TYPE} == "xpm"
.  include "../../x11/Xaw-Xpm/buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.Xaw-Xpm}
.elif ${XAW_TYPE} == "3d"
.  include "../../x11/libXaw3d/buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.Xaw3d}
.elif ${XAW_TYPE} == "neXtaw"
.  include "../../x11/neXtaw/buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.neXtaw}
.elif ${XAW_TYPE} == "standard"
.  if ${X11_TYPE} == "modular"
.    include "../../x11/libXaw/buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${BUILDLINK_PREFIX.libXaw}
.  else
.    include "../../mk/x11.buildlink3.mk"
BUILDLINK_PREFIX.Xaw?=	${X11BASE}
.  endif
.else
PKG_FAIL_REASON+=	"[xaw.buildlink3.mk] Invalid value ${XAW_TYPE} for XAW_TYPE."
.endif

.endif	# XAW_BUILDLINK3_MK
