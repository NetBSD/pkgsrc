# $NetBSD: xaw.buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:44 jlam Exp $
#
# This Makefile fragment is included by packages that use Xaw.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally set XAW_TYPE to the Xaw library desired, and
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(XAW_BUILDLINK2_MK)
XAW_BUILDLINK2_MK=	# defined

# Pull in setting for XAW_TYPE.
XAW_TYPE?=	standard

.include "../../mk/bsd.prefs.mk"

.if ${XAW_TYPE} == "xpm"
.include "../../x11/Xaw-Xpm/buildlink2.mk"
.elif ${XAW_TYPE} == "3d"
.include "../../x11/Xaw3d/buildlink2.mk"
.else
LIBXAW?=	-L${X11BASE}/lib -lXaw
.endif
MAKE_ENV+=	LIBXAW="${LIBXAW}"

.endif	# XAW_BUILDLINK2_MK
