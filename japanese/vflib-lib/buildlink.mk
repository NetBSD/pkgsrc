# $NetBSD: buildlink.mk,v 1.3 2001/06/10 00:09:32 jlam Exp $
#
# This Makefile fragment is included by packages that use VFlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define VFLIB_REQD to the version of VFlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(VFLIB_BUILDLINK_MK)
VFLIB_BUILDLINK_MK=	# defined

VFLIB_REQD?=		2.24.2
DEPENDS+=		ja-vflib-lib>=${VFLIB_REQD}:../../japanese/vflib-lib

VFLIB_HEADERS=		${LOCALBASE}/include/VF.h
VFLIB_LIBS=		${LOCALBASE}/lib/libVFlib2.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

.include "../../graphics/freetype-lib/buildlink.mk"

VFLIB_BUILDLINK_COOKIE=		${WRKDIR}/.vflib_buildlink_done
VFLIB_BUILDLINK_TARGETS=	link-vflib-headers
VFLIB_BUILDLINK_TARGETS+=	link-vflib-libs
BUILDLINK_TARGETS+=		${VFLIB_BUILDLINK_COOKIE}

pre-configure: ${VFLIB_BUILDLINK_COOKIE}

${VFLIB_BUILDLINK_COOKIE}: ${VFLIB_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${VFLIB_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-vflib-headers:
	@${ECHO} "Linking vflib headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${VFLIB_HEADERS}; do				\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-vflib-libs:
	@${ECHO} "Linking vflib libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${VFLIB_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# VFLIB_BUILDLINK_MK
