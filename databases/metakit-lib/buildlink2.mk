# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/12/04 18:47:15 drochner Exp $
#
# This Makefile fragment is included by packages that use metakit-lib.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(METAKIT_LIB_BUILDLINK2_MK)
METAKIT_LIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			metakit-lib
BUILDLINK_DEPENDS.metakit-lib?=		metakit-lib>=2.4.8
BUILDLINK_PKGSRCDIR.metakit-lib?=		../../databases/metakit-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.metakit-lib=metakit-lib
BUILDLINK_PREFIX.metakit-lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.metakit-lib+=	include/mk4.h
BUILDLINK_FILES.metakit-lib+=	include/mk4.inl
BUILDLINK_FILES.metakit-lib+=	include/mk4io.h
BUILDLINK_FILES.metakit-lib+=	include/mk4str.h
BUILDLINK_FILES.metakit-lib+=	include/mk4str.inl
BUILDLINK_FILES.metakit-lib+=	lib/libmk4.*


BUILDLINK_TARGETS+=	metakit-lib-buildlink

metakit-lib-buildlink: _BUILDLINK_USE

.endif	# METAKIT_LIB_BUILDLINK2_MK
