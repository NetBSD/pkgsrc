# $NetBSD: buildlink.mk,v 1.2 2002/01/24 13:49:59 wiz Exp $
#
# This Makefile fragment is included by packages that use libpspell.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libpspell to the dependency pattern
#     for the version of libpspell desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBPSPELL_BUILDLINK_MK)
LIBPSPELL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libpspell?=	libpspell>=0.12.2nb1
DEPENDS+=	${BUILDLINK_DEPENDS.libpspell}:../../textproc/libpspell

EVAL_PREFIX+=			BUILDLINK_PREFIX.libpspell=libpspell
BUILDLINK_PREFIX.libpspell_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libpspell=		include/pspell/*
BUILDLINK_FILES.libpspell+=		lib/libpspell*

BUILDLINK_TARGETS.libpspell=	libpspell-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libpspell}

pre-configure: ${BUILDLINK_TARGETS.libpspell}
libpspell-buildlink: _BUILDLINK_USE

.endif	# LIBPSPELL_BUILDLINK_MK
