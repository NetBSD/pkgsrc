# $NetBSD: buildlink.mk,v 1.12 2002/09/10 16:06:49 wiz Exp $
#
# This Makefile fragment is included by packages that use libxml2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libxml2 to the dependency pattern
#     for the version of libxml2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBXML2_BUILDLINK_MK)
LIBXML2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libxml2?=	libxml2>=2.4.24nb1
DEPENDS+=	${BUILDLINK_DEPENDS.libxml2}:../../textproc/libxml2

EVAL_PREFIX+=			BUILDLINK_PREFIX.libxml2=libxml2
BUILDLINK_PREFIX.libxml2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libxml2=	include/libxml2/libxml/*
BUILDLINK_FILES.libxml2+=	lib/libxml2.*
BUILDLINK_FILES.libxml2+=	lib/xml2Conf.sh

# The libxml2 headers should be found at the same location as for libxml.I
BUILDLINK_TRANSFORM.libxml2=	-e "s|/include/libxml2/|/include/|g"
BUILDLINK_CONFIG_WRAPPER_SED+=  \
	-e "s|-I${BUILDLINK_PREFIX.libxml2}/include/libxml2|-I${BUILDLINK_DIR}/include/libxml -I${BUILDLINK_DIR}/include/|g"

.include "../../devel/zlib/buildlink.mk"
.include "../../converters/libiconv/buildlink.mk"

BUILDLINK_TARGETS.libxml2=	libxml2-buildlink
BUILDLINK_TARGETS.libxml2+=	libxml2-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libxml2}

BUILDLINK_CONFIG.libxml2=	\
		${BUILDLINK_PREFIX.libxml2}/bin/xml2-config
BUILDLINK_CONFIG_WRAPPER.libxml2=	\
		${BUILDLINK_DIR}/bin/xml2-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libxml2}|${BUILDLINK_CONFIG.libxml2}|g"

.if defined(USE_CONFIG_WRAPPER)
XML2_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libxml2}
CONFIGURE_ENV+=		XML2_CONFIG="${XML2_CONFIG}"
MAKE_ENV+=		XML2_CONFIG="${XML2_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libxml2}
libxml2-buildlink: _BUILDLINK_USE
libxml2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBXML2_BUILDLINK_MK
