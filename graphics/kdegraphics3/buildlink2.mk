# $NetBSD: buildlink2.mk,v 1.10 2003/12/08 14:41:40 wiz Exp $
#
# This Makefile fragment is included by packages that use kdegraphics.
#

.if !defined(KDEGRAPHICS_BUILDLINK2_MK)
KDEGRAPHICS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdegraphics
BUILDLINK_DEPENDS.kdegraphics?=		kdegraphics>=3.1.4
BUILDLINK_PKGSRCDIR.kdegraphics?=		../../graphics/kdegraphics3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdegraphics=kdegraphics
BUILDLINK_PREFIX.kdegraphics_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdegraphics+=	include/kmultipageInterface.h
BUILDLINK_FILES.kdegraphics+=	lib/kcolorchooser.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_pdf.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_png.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_ps.*
BUILDLINK_FILES.kdegraphics+=	lib/kuickshow.*
BUILDLINK_FILES.kdegraphics+=	lib/kview.*
BUILDLINK_FILES.kdegraphics+=	lib/libkdvi.*
BUILDLINK_FILES.kdegraphics+=	lib/libkfax.*
BUILDLINK_FILES.kdegraphics+=	lib/libkghostview.*
BUILDLINK_FILES.kdegraphics+=	lib/libkmultipage.*
BUILDLINK_FILES.kdegraphics+=	lib/libkpagetest.*
BUILDLINK_FILES.kdegraphics+=	lib/libkuickshow_main.*
BUILDLINK_FILES.kdegraphics+=	lib/libkview_main.*
BUILDLINK_FILES.kdegraphics+=	lib/libkviewerpart.*
BUILDLINK_FILES.kdegraphics+=	lib/libkviewpart.*

.include "../../graphics/imlib/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdegraphics-buildlink

kdegraphics-buildlink: _BUILDLINK_USE

.endif	# KDEGRAPHICS_BUILDLINK2_MK
