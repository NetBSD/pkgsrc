# $NetBSD: buildlink.mk,v 1.5 2002/02/07 07:31:48 martti Exp $
#
# This Makefile fragment is included by packages that use libusb.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libusb to the dependency pattern
#     for the version of libusb desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBUSB_BUILDLINK_MK)
LIBUSB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libusb?=	libusb>=0.1.5
DEPENDS+=	${BUILDLINK_DEPENDS.libusb}:../../devel/libusb

EVAL_PREFIX+=			BUILDLINK_PREFIX.libusb=libusb
BUILDLINK_FILES.libusb=		include/usb.h
BUILDLINK_FILES.libusb+=	lib/libusb-*.*
BUILDLINK_FILES.libusb+=	lib/libusb.*

BUILDLINK_TARGETS.libusb=	libusb-buildlink
BUILDLINK_TARGETS.libusb+=	libusb-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libusb}

BUILDLINK_CONFIG.libusb=	\
			${BUILDLINK_PREFIX.libusb}/bin/libusb-config
BUILDLINK_CONFIG_WRAPPER.libusb=	\
	 		${BUILDLINK_DIR}/bin/libusb-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libusb}|${BUILDLINK_CONFIG.libusb}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBUSB_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libusb}
CONFIGURE_ENV+=		LIBUSB_CONFIG="${LIBUSB_CONFIG}"
MAKE_ENV+=		LIBUSB_CONFIG="${LIBUSB_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libusb}
libusb-buildlink: _BUILDLINK_USE
libusb-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBUSB_BUILDLINK_MK
