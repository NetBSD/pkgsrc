# $NetBSD: buildlink2.mk,v 1.7 2003/01/19 04:38:01 uebayasi Exp $

.if !defined(GUILE14_BUILDLINK2_MK)
GUILE14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guile14
BUILDLINK_DEPENDS.guile14?=	guile14>=1.4nb2
BUILDLINK_PKGSRCDIR.guile14?=	../../lang/guile14

EVAL_PREFIX+=				BUILDLINK_PREFIX.guile14=guile14
BUILDLINK_PREFIX.guile14=		${LOCALBASE}
BUILDLINK_PREFIX.guile14_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.guile14+=		guile/1.4/include/libguile.*
BUILDLINK_FILES.guile14+=		guile/1.4/include/guile/*
BUILDLINK_FILES.guile14+=		guile/1.4/include/guile-readline/*
BUILDLINK_FILES.guile14+=		guile/1.4/include/libguile/*
BUILDLINK_FILES.guile14+=		guile/1.4/lib/libguile.*
BUILDLINK_FILES.guile14+=		guile/1.4/lib/libguilereadline.*

USE_GNU_READLINE=	# defined

.include "../../devel/libtool/buildlink2.mk"	# For libltdl
.include "../../devel/readline/buildlink2.mk"

BUILDLINK_TARGETS+=	guile14-buildlink
BUILDLINK_TARGETS+=	guile14-buildlink-bin

guile14-buildlink: _BUILDLINK_USE

# Put only bin/guile, bin/guile-config, and bin/guile-snarf into
# ${BUILDLINK_DIR}/bin.  Other files (headers/libraries) are put in
# ${BUILDLINK_DIR}/guile/1.4/...
guile14-buildlink-bin:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_BUILDLINK_MSG} "Linking Guile executables."
	${_PKG_SILENT}${_PKG_DEBUG}${LN} -s ${BUILDLINK_PREFIX.guile14}/guile/1.4/bin/guile* ${BUILDLINK_DIR}/bin

.endif	# GUILE14_BUILDLINK2_MK
