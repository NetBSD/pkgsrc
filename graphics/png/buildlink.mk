# $NetBSD: buildlink.mk,v 1.4 2001/06/10 00:09:32 jlam Exp $
#
# This Makefile fragment is included by packages that use libpng.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define PNG_REQD to the version of libpng desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(PNG_BUILDLINK_MK)
PNG_BUILDLINK_MK=	# defined

PNG_REQD?=		1.0.11
DEPENDS+=		png>=${PNG_REQD}:../../graphics/png

PNG_HEADERS=		${LOCALBASE}/include/png.h
PNG_HEADERS+=		${LOCALBASE}/include/pngconf.h
PNG_LIBS=		${LOCALBASE}/lib/libpng.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

.include "../../devel/zlib/buildlink.mk"

PNG_BUILDLINK_COOKIE=		${WRKDIR}/.png_buildlink_done
PNG_BUILDLINK_TARGETS=		link-png-headers
PNG_BUILDLINK_TARGETS+=		link-png-libs
BUILDLINK_TARGETS+=		${PNG_BUILDLINK_COOKIE}

pre-configure: ${PNG_BUILDLINK_COOKIE}

${PNG_BUILDLINK_COOKIE}: ${PNG_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${PNG_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-png-headers:
	@${ECHO} "Linking png headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${PNG_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-png-libs:
	@${ECHO} "Linking png libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${PNG_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# PNG_BUILDLINK_MK
