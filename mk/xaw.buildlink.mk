# $NetBSD: xaw.buildlink.mk,v 1.1.2.1 2002/08/21 05:19:47 jlam Exp $
#
# This Makefile fragment is included by packages that use Xaw.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally set XAW_TYPE to the Xaw library desired, and
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(XAW_BUILDLINK_MK)
XAW_BUILDLINK_MK=	# defined

# Pull in setting for XAW_TYPE.
XAW_TYPE?=	standard
.include "../../mk/bsd.prefs.mk"

.if ${XAW_TYPE} == "xpm"
.include "../../x11/Xaw-Xpm/buildlink.mk"
.elif ${XAW_TYPE} == "3d"
.include "../../x11/Xaw3d/buildlink.mk"
.elif ${XAW_TYPE} == "neXtaw"
.include "../../x11/neXtaw/buildlink.mk"
.else
LIBXAW?=	-L${BUILDLINK_X11_DIR}/lib -lXaw
MAKE_ENV+=	LIBXAW="${LIBXAW}"
.endif

.endif	# XAW_BUILDLINK_MK
