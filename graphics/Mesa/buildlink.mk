# $NetBSD: buildlink.mk,v 1.3 2001/06/10 00:09:31 jlam Exp $
#
# This Makefile fragment is included by packages that use Mesa.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define MESA_REQD to the version of Mesa desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(MESA_BUILDLINK_MK)
MESA_BUILDLINK_MK=	# defined

MESA_REQD?=		3.2.1

# We double-list because we're not sure if the files are in ${X11BASE}
# or in ${LOCALBASE}.

MESA_HEADERS=		${X11BASE}/include/GL/*
MESA_HEADERS+=		${LOCALBASE}/include/GL/*

MESA_LIBS=		${X11BASE}/lib/libGL.*
MESA_LIBS+=		${X11BASE}/lib/libGLU.*
MESA_LIBS+=		${X11BASE}/lib/libglut.*
MESA_LIBS+=		${LOCALBASE}/lib/libGL.*
MESA_LIBS+=		${LOCALBASE}/lib/libGLU.*
MESA_LIBS+=		${LOCALBASE}/lib/libglut.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

MESA_BUILDLINK_COOKIE=		${WRKDIR}/.Mesa_buildlink_done
MESA_BUILDLINK_TARGETS=		link-Mesa-headers
MESA_BUILDLINK_TARGETS+=	link-Mesa-libs
BUILDLINK_TARGETS+=		${MESA_BUILDLINK_COOKIE}

pre-configure: ${MESA_BUILDLINK_COOKIE}

${MESA_BUILDLINK_COOKIE}: ${MESA_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${MESA_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-Mesa-headers:
	@${ECHO} "Linking Mesa headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/GL
	@${RM} -f ${BUILDLINK_INCDIR}/GL/*
	@for inc in ${MESA_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/GL/`${BASENAME} $${inc}`; \
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-Mesa-libs:
	@${ECHO} "Linking Mesa libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${MESA_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# MESA_BUILDLINK_MK
