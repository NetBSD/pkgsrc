# $NetBSD: buildlink.mk,v 1.1.2.2 2002/06/23 18:59:50 jlam Exp $
#
# This Makefile fragment is included by packages that use fam.
#
# This file was created automatically using createbuildlink 1.6.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.fam to the dependency pattern
#     for the version of fam desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FAM_BUILDLINK_MK)
FAM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.fam?=		fam>=2.6.7
DEPENDS+=	${BUILDLINK_DEPENDS.fam}:../../sysutils/fam

EVAL_PREFIX+=	BUILDLINK_PREFIX.fam=fam
BUILDLINK_PREFIX.fam_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fam+=	include/fam.h
BUILDLINK_FILES.fam+=	lib/fam/editconf.perl
BUILDLINK_FILES.fam+=	lib/libfam.*


BUILDLINK_TARGETS.fam=	fam-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.fam}

pre-configure: ${BUILDLINK_TARGETS}
fam-buildlink: _BUILDLINK_USE

.endif	# FAM_BUILDLINK_MK
