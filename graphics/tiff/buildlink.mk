# $NetBSD: buildlink.mk,v 1.4 2001/06/10 00:09:32 jlam Exp $
#
# This Makefile fragment is included by packages that use libtiff.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define TIFF_REQD to the version of libtiff desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(TIFF_BUILDLINK_MK)
TIFF_BUILDLINK_MK=	# defined

TIFF_REQD?=		3.5.4
DEPENDS+=		tiff>=${TIFF_REQD}:../../graphics/tiff

TIFF_HEADERS=		${LOCALBASE}/include/tiff.h
TIFF_HEADERS+=		${LOCALBASE}/include/tiffconf.h
TIFF_HEADERS+=		${LOCALBASE}/include/tiffio.h
TIFF_LIBS=		${LOCALBASE}/lib/libtiff.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"

TIFF_BUILDLINK_COOKIE=		${WRKDIR}/.tiff_buildlink_done
TIFF_BUILDLINK_TARGETS=		link-tiff-headers
TIFF_BUILDLINK_TARGETS+=	link-tiff-libs
BUILDLINK_TARGETS+=		${TIFF_BUILDLINK_COOKIE}

pre-configure: ${TIFF_BUILDLINK_COOKIE}

${TIFF_BUILDLINK_COOKIE}: ${TIFF_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${TIFF_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-tiff-headers:
	@${ECHO} "Linking tiff headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${TIFF_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-tiff-libs:
	@${ECHO} "Linking tiff libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${TIFF_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# TIFF_BUILDLINK_MK
