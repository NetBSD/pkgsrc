# $NetBSD: buildlink.mk,v 1.3 2001/06/10 00:09:31 jlam Exp $
#
# This Makefile fragment is included by packages that use freetype.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define FREETYPE_REQD to the version of freetype desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(FREETYPE_BUILDLINK_MK)
FREETYPE_BUILDLINK_MK=	# defined

FREETYPE_REQD?=		1.3.1
DEPENDS+=		freetype-lib>=${FREETYPE_REQD}:../../graphics/freetype-lib

FREETYPE_HEADERS=	${LOCALBASE}/include/freetype/*
FREETYPE_LIBS=		${LOCALBASE}/lib/libttf.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

.include "../../devel/gettext-lib/buildlink.mk"

FREETYPE_BUILDLINK_COOKIE=	${WRKDIR}/.freetype_buildlink_done
FREETYPE_BUILDLINK_TARGETS=	link-freetype-headers
FREETYPE_BUILDLINK_TARGETS+=	link-freetype-libs
BUILDLINK_TARGETS+=		${FREETYPE_BUILDLINK_COOKIE}

pre-configure: ${FREETYPE_BUILDLINK_COOKIE}

${FREETYPE_BUILDLINK_COOKIE}: ${FREETYPE_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${FREETYPE_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-freetype-headers:
	@${ECHO} "Linking freetype headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/freetype
	@${RM} -f ${BUILDLINK_INCDIR}/freetype/*
	@for inc in ${FREETYPE_HEADERS}; do				\
		dest=${BUILDLINK_INCDIR}/freetype/`${BASENAME} $${inc}`; \
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-freetype-libs:
	@${ECHO} "Linking freetype libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${FREETYPE_LIBS}; do				\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# FREETYPE_BUILDLINK_MK
