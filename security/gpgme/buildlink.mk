# $NetBSD: buildlink.mk,v 1.1 2002/03/17 14:53:57 uebayasi Exp $
#
# This Makefile fragment is included by packages that use GPGME.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gpgme to the dependency pattern
#     for the version of GPGME desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GPGME_BUILDLINK_MK)
GPGME_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gpgme?=	gpgme>=0.3.0
DEPENDS+=	${BUILDLINK_DEPENDS.gpgme}:../../security/gpgme

EVAL_PREFIX+=		BUILDLINK_PREFIX.gpgme=gpgme
BUILDLINK_PREFIX.gpgme_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gpgme+=	include/gpgme.h
BUILDLINK_FILES.gpgme+=	lib/libgpgme.*

BUILDLINK_TARGETS.gpgme=	gpgme-buildlink
BUILDLINK_TARGETS.gpgme+=	gpgme-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gpgme}

BUILDLINK_CONFIG.gpgme=	${BUILDLINK_PREFIX.gpgme}/bin/gpgme-config
BUILDLINK_CONFIG_WRAPPER.gpgme=	${BUILDLINK_DIR}/bin/gpgme-config
REPLACE_BUILDLINK_SED+= \
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gpgme}|${BUILDLINK_CONFIG.gpgme}|g"

.if defined(USE_CONFIG_WRAPPER)
GPGME_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gpgme}
CONFIGURE_ENV+=		GPGME_CONFIG="${GPGME_CONFIG}"
MAKE_ENV+=		GPGME_CONFIG="${GPGME_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gpgme}
gpgme-buildlink: _BUILDLINK_USE
gpgme-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GPGME_BUILDLINK_MK
