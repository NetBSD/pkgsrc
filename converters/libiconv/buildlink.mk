# $NetBSD: buildlink.mk,v 1.2 2001/06/10 00:09:29 jlam Exp $
#
# This Makefile fragment is included by packages that use libiconv.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define ICONV_REQD to the version of libiconv desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(ICONV_BUILDLINK_MK)
ICONV_BUILDLINK_MK=	# defined

ICONV_REQD?=		1.5
DEPENDS+=		libiconv>=${ICONV_REQD}:../../converters/libiconv

ICONV_HEADERS=		${LOCALBASE}/include/iconv.h
ICONV_HEADERS+=		${LOCALBASE}/include/libcharset.h
ICONV_LIBS=		${LOCALBASE}/lib/libcharset.*
ICONV_LIBS+=		${LOCALBASE}/lib/libiconv.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

ICONV_BUILDLINK_COOKIE=		${WRKDIR}/.iconv_buildlink_done
ICONV_BUILDLINK_TARGETS=	link-iconv-headers
ICONV_BUILDLINK_TARGETS+=	link-iconv-libs
BUILDLINK_TARGETS+=		${ICONV_BUILDLINK_COOKIE}

pre-configure: ${ICONV_BUILDLINK_COOKIE}

${ICONV_BUILDLINK_COOKIE}: ${ICONV_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${ICONV_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-iconv-headers:
	@${ECHO} "Linking iconv headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${ICONV_HEADERS}; do				\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
        done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-iconv-libs:
	@${ECHO} "Linking iconv libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${ICONV_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# ICONV_BUILDLINK_MK
