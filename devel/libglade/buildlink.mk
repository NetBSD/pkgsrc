# $NetBSD: buildlink.mk,v 1.4 2001/10/06 11:47:31 rh Exp $
#
# This Makefile fragment is included by packages that use libglade.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libglade to the dependency pattern
#     for the version of libglade desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBGLADE_BUILDLINK_MK)
LIBGLADE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libglade?=	libglade>=0.17
DEPENDS+=	${BUILDLINK_DEPENDS.libglade}:../../devel/libglade

EVAL_PREFIX+=			BUILDLINK_PREFIX.libglade=libglade
BUILDLINK_PREFIX.libglade_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libglade=	include/libglade-1.0/glade/*
BUILDLINK_FILES.libglade+=	lib/libglade.*
BUILDLINK_FILES.libglade+=	lib/libglade-gnome.*
BUILDLINK_FILES.libglade+=	lib/libgladeConf.sh

BUILDLINK_CPPFLAGS+=		-I${BUILDLINK_DIR}/include/libglade-1.0

BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${BUILDLINK_PREFIX.libglade}\(/include/libglade-1.0\)|-I${BUILDLINK_DIR}\1|g"

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../audio/esound/buildlink.mk"

BUILDLINK_TARGETS.libglade=	libglade-buildlink
BUILDLINK_TARGETS.libglade+=	libglade-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libglade}

BUILDLINK_CONFIG.libglade=	\
		${BUILDLINK_PREFIX.libglade}/bin/libglade-config
BUILDLINK_CONFIG_WRAPPER.libglade=	\
		${BUILDLINK_DIR}/bin/libglade-config

.if defined(USE_CONFIG_WRAPPER)
LIBGLADE_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.libglade}
CONFIGURE_ENV+=		LIBGLADE_CONFIG="${LIBGLADE_CONFIG}"
MAKE_ENV+=		LIBGLADE_CONFIG="${LIBGLADE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libglade}
libglade-buildlink: _BUILDLINK_USE
libglade-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBGLADE_BUILDLINK_MK
