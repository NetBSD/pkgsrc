# $NetBSD: buildlink.mk,v 1.1 2001/11/26 06:22:03 jlam Exp $
#
# This Makefile fragment is included by packages that use kakasi.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.kakasi to the dependency pattern
#     for the version of kakasi desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(KAKASI_BUILDLINK_MK)
KAKASI_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.kakasi?=	kakasi>=2.3.0
DEPENDS+=	${BUILDLINK_DEPENDS.kakasi}:../../japanese/kakasi

EVAL_PREFIX+=				BUILDLINK_PREFIX.kakasi=kakasi
BUILDLINK_PREFIX.kakasi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kakasi=			include/libkakasi.h
BUILDLINK_FILES.kakasi+=		lib/libkakasi.*

BUILDLINK_TARGETS.kakasi=	kakasi-buildlink
BUILDLINK_TARGETS.kakasi+=	kakasi-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.kakasi}

BUILDLINK_CONFIG.kakasi=	\
	${BUILDLINK_PREFIX.kakasi}/bin/kakasi-config
BUILDLINK_CONFIG_WRAPPER.kakasi=	\
	${BUILDLINK_DIR}/bin/kakasi-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.kakasi}|${BUILDLINK_CONFIG.kakasi}|g"

.if defined(USE_CONFIG_WRAPPER)
KAKASI_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.kakasi}
CONFIGURE_ENV+=		KAKASI_CONFIG="${KAKASI_CONFIG}"
MAKE_ENV+=		KAKASI_CONFIG="${KAKASI_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.kakasi}
kakasi-buildlink: _BUILDLINK_USE
kakasi-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# KAKASI_BUILDLINK_MK
