# $NetBSD: buildlink.mk,v 1.2 2002/08/25 19:22:55 jlam Exp $
#
# This Makefile fragment is included by packages that use Canna.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.canna to the dependency pattern
#     for the version of Canna desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CANNA_BUILDLINK_MK)
CANNA_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.canna?=	Canna-lib>=3.5.2
DEPENDS+=	${BUILDLINK_DEPENDS.canna}:../../inputmethod/canna-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.canna=canna-lib
BUILDLINK_PREFIX.canna_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.canna=		include/canna/RK.h
BUILDLINK_FILES.canna+=		include/canna/jrkanji.h
BUILDLINK_FILES.canna+=		include/canna/keydef.h
BUILDLINK_FILES.canna+=		include/canna/mfdef.h
BUILDLINK_FILES.canna+=		lib/libRKC.*
BUILDLINK_FILES.canna+=		lib/libRKC16.*
BUILDLINK_FILES.canna+=		lib/libcanna.*
BUILDLINK_FILES.canna+=		lib/libcanna16.*

BUILDLINK_TARGETS.canna=	canna-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.canna}

pre-configure: ${BUILDLINK_TARGETS.canna}
canna-buildlink: _BUILDLINK_USE

.endif	# CANNA_BUILDLINK_MK
