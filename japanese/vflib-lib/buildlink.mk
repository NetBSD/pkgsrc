# $NetBSD: buildlink.mk,v 1.1 2001/05/28 03:09:11 jlam Exp $
#
# This Makefile fragment is included by packages that use VFlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define VFLIB_REQD to the version of VFlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(VFLIB_BUILDLINK_MK)
VFLIB_BUILDLINK_MK=	# defined

.include "../../graphics/freetype-lib/buildlink.mk"

VFLIB_REQD?=		2.24.2
DEPENDS+=		ja-vflib-lib>=${VFLIB_REQD}:../../japanese/vflib-lib

VFLIB_HEADERS=		${LOCALBASE}/include/VF.h
VFLIB_LIBS=		${LOCALBASE}/lib/libVFlib2.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-vflib-headers
BUILDLINK_TARGETS+=	link-vflib-libs

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
