# $NetBSD: buildlink.mk,v 1.2 2001/06/10 00:09:31 jlam Exp $
#
# This Makefile fragment is included by packages that use zlib. 
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define ZLIB_REQD to the version of zlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(ZLIB_BUILDLINK_MK)
ZLIB_BUILDLINK_MK=	# defined

ZLIB_REQD?=		1.1.3

.if exists(/usr/include/zlib.h)
_NEED_ZLIB=		NO
.else
_NEED_ZLIB=		YES
.endif

.if ${_NEED_ZLIB} == "YES"
DEPENDS+=		zlib>=${ZLIB_REQD}:../../devel/zlib
ZLIB_HEADERS=		${LOCALBASE}/include/zconf.h
ZLIB_HEADERS=		${LOCALBASE}/include/zlib.h
ZLIB_LIBS=		${LOCALBASE}/lib/libz.*
.else
ZLIB_HEADERS=		/usr/include/zconf.h
ZLIB_HEADERS+=		/usr/include/zlib.h
ZLIB_LIBS=		/usr/lib/libz.*
.endif

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

ZLIB_BUILDLINK_COOKIE=		${WRKDIR}/.zlib_buildlink_done
ZLIB_BUILDLINK_TARGETS=		link-zlib-headers
ZLIB_BUILDLINK_TARGETS+=	link-zlib-libs
BUILDLINK_TARGETS+=		${ZLIB_BUILDLINK_COOKIE}

pre-configure: ${ZLIB_BUILDLINK_COOKIE}

${ZLIB_BUILDLINK_COOKIE}: ${ZLIB_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${ZLIB_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-zlib-headers:
	@${ECHO} "Linking zlib headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${ZLIB_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-zlib-libs:
	@${ECHO} "Linking zlib libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${ZLIB_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# ZLIB_BUILDLINK_MK
