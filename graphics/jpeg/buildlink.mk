# $NetBSD: buildlink.mk,v 1.1 2001/05/26 16:30:19 jlam Exp $
#
# This Makefile fragment is included by packages that use libjpeg.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define JPEG_REQD to the version of libjpeg desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(JPEG_BUILDLINK_MK)
JPEG_BUILDLINK_MK=	# defined

JPEG_REQD?=		6
DEPENDS+=		jpeg>=${JPEG_REQD}:../../graphics/jpeg

JPEG_HEADERS=		${LOCALBASE}/include/jconfig.h
JPEG_HEADERS+=		${LOCALBASE}/include/jpeglib.h
JPEG_HEADERS+=		${LOCALBASE}/include/jmorecfg.h
JPEG_HEADERS+=		${LOCALBASE}/include/jerror.h
JPEG_LIBS=		${LOCALBASE}/lib/libjpeg.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-jpeg-headers
BUILDLINK_TARGETS+=	link-jpeg-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-jpeg-headers:
	@${ECHO} "Linking jpeg headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${JPEG_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
        done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-jpeg-libs:
	@${ECHO} "Linking jpeg libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${JPEG_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# JPEG_BUILDLINK_MK
