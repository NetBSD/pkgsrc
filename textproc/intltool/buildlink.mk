# $NetBSD: buildlink.mk,v 1.1.1.1 2002/05/06 13:15:21 rh Exp $
#
# This Makefile fragment is included by packages that use intltool.
#
# This file was created automatically using createbuildlink 1.2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.intltool to the dependency pattern
#     for the version of intltool desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(INTLTOOL_BUILDLINK_MK)
INTLTOOL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.intltool?=		intltool>=0.18
DEPENDS+=	${BUILDLINK_DEPENDS.intltool}:../../textproc/intltool

EVAL_PREFIX+=	BUILDLINK_PREFIX.intltool=intltool
BUILDLINK_PREFIX.intltool_DEFAULT=	${LOCALBASE}

.include "../../lang/perl5/buildlink.mk"

BUILDLINK_TARGETS.intltool=	intltool-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.intltool}

pre-configure: ${BUILDLINK_TARGETS}
intltool-buildlink: _BUILDLINK_USE

.endif	# INTLTOOL_BUILDLINK_MK
