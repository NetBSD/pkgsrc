# $NetBSD: buildlink.mk,v 1.1 2001/11/21 22:22:10 jlam Exp $
#
# This Makefile fragment is included by packages that use cyrus-sasl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.cyrus-sasl to the dependency pattern
#     for the version of cyrus-sasl desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CYRUS_SASL_BUILDLINK_MK)
CYRUS_SASL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.cyrus-sasl?=	cyrus-sasl>=1.5.24nb2
DEPENDS+=	${BUILDLINK_DEPENDS.cyrus-sasl}:../../security/cyrus-sasl

EVAL_PREFIX+=	BUILDLINK_PREFIX.cyrus-sasl=cyrus-sasl
BUILDLINK_PREFIX.cyrus-sasl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cyrus-sasl=		include/hmac-md5.h
BUILDLINK_FILES.cyrus-sasl+=		include/sasl.h
BUILDLINK_FILES.cyrus-sasl+=		include/saslplug.h
BUILDLINK_FILES.cyrus-sasl+=		include/saslutil.h
BUILDLINK_FILES.cyrus-sasl+=		lib/libsasl.*

BUILDLINK_TARGETS.cyrus-sasl=		cyrus-sasl-buildlink
BUILDLINK_TARGETS.cyrus-sasl+=		cyrus-sasl-buildlink-config-wrapper
BUILDLINK_TARGETS+=			${BUILDLINK_TARGETS.cyrus-sasl}

BUILDLINK_CONFIG.cyrus-sasl=		${BUILDLINK_PREFIX.cyrus-sasl}/bin/sasl-config
BUILDLINK_CONFIG_WRAPPER.cyrus-sasl=	${BUILDLINK_DIR}/bin/sasl-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.cyrus-sasl}|${BUILDLINK_CONFIG.cyrus-sasl}|g"

.if defined(USE_CONFIG_WRAPPER)
SASL_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.cyrus-sasl}
CONFIGURE_ENV+=		SASL_CONFIG="${SASL_CONFIG}"
MAKE_ENV+=		SASL_CONFIG="${SASL_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.cyrus-sasl}
cyrus-sasl-buildlink: _BUILDLINK_USE
cyrus-sasl-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# CYRUS_SASL_BUILDLINK_MK
