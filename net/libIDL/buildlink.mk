# $NetBSD: buildlink.mk,v 1.3 2002/09/10 16:06:47 wiz Exp $
#
# This Makefile fragment is included by packages that use idl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.idl to the dependency pattern
#     for the version of idl desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBIDL2_BUILDLINK_MK)
LIBIDL2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.idl?=	libIDL>=0.7.4nb2
DEPENDS+=	${BUILDLINK_DEPENDS.idl}:../../net/libIDL

EVAL_PREFIX+=		BUILDLINK_PREFIX.idl=idl
BUILDLINK_PREFIX.idl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.idl=	include/libIDL-2.0/libIDL/*
BUILDLINK_FILES.idl+=	lib/libIDL-2.*

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"

BUILDLINK_TARGETS.idl=	idl-buildlink
BUILDLINK_TARGETS.idl+=idl-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.idl}
BUILDLINK_TARGETS+=	${BUILDLINK_PKG_CONFIG}

BUILDLINK_CONFIG.idl=${BUILDLINK_PREFIX.idl}/bin/libIDL-config-2
BUILDLINK_CONFIG_WRAPPER.idl=${BUILDLINK_DIR}/bin/libIDL-config-2
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.idl}|${BUILDLINK_CONFIG.idl}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBIDL2_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.idl}
CONFIGURE_ENV+=	LIBIDL2_CONFIG="${LIBIDL2_CONFIG}"
MAKE_ENV+=	LIBIDL2_CONFIG="${LIBIDL2_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS}
idl-buildlink: _BUILDLINK_USE
idl-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBIDL2_BUILDLINK_MK
