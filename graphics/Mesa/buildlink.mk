# $NetBSD: buildlink.mk,v 1.7 2001/09/09 03:19:42 jlam Exp $
#
# This Makefile fragment is included by packages that use Mesa.
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (3) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MESA_BUILDLINK_MK)
MESA_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

USE_MESA=		# defined

# We double-list because we're not sure if the files are in ${X11BASE}
# or in ${LOCALBASE}.

BUILDLINK_PREFIX.Mesa-x11base=	${X11BASE}
BUILDLINK_FILES.Mesa-x11base=	include/GL/*
BUILDLINK_FILES.Mesa-x11base+=	lib/libGL.*
BUILDLINK_FILES.Mesa-x11base+=	lib/libGLU.*
BUILDLINK_FILES.Mesa-x11base+=	lib/libglut.*

BUILDLINK_TARGETS.Mesa=		Mesa-x11base-buildlink

BUILDLINK_PREFIX.Mesa-localbase=	${LOCALBASE}
BUILDLINK_FILES.Mesa-localbase=		include/GL/*
BUILDLINK_FILES.Mesa-localbase+=	lib/libGL.*
BUILDLINK_FILES.Mesa-localbase+=	lib/libGLU.*
BUILDLINK_FILES.Mesa-localbase+=	lib/libglut.*

BUILDLINK_TARGETS.Mesa+=	Mesa-localbase-buildlink
BUILDLINK_TARGETS.Mesa+=	Mesa-extra-includes-buildlink

BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.Mesa}

pre-configure: ${BUILDLINK_TARGETS.Mesa}
Mesa-x11base-buildlink: _BUILDLINK_USE
Mesa-localbase-buildlink: _BUILDLINK_USE

Mesa-extra-includes-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "Touching extra Mesa headers in ${BUILDLINK_DIR}."; \
	extra_includes="						\
		include/GL/xmesa.h					\
	";								\
	for file in $${extra_includes}; do				\
		header=${BUILDLINK_DIR}/$${file};			\
		if [ ! -e $${header} ]; then				\
			${TOUCH} ${TOUCH_FLAGS} $${header};		\
		fi;							\
	done

.endif	# MESA_BUILDLINK_MK
