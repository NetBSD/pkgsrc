# $NetBSD: buildlink.mk,v 1.2 2001/06/10 00:09:29 jlam Exp $
#
# This Makefile fragment is included by packages that use gdbm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define GDBM_REQD to the version of gdbm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(GDBM_BUILDLINK_MK)
GDBM_BUILDLINK_MK=	# defined

GDBM_REQD?=		1.7.3
DEPENDS+=		gdbm>=${GDBM_REQD}:../../databases/gdbm

GDBM_HEADERS=		${LOCALBASE}/include/gdbm.h
GDBM_LIBS=		${LOCALBASE}/lib/libgdbm.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

GDBM_BUILDLINK_COOKIE=		${WRKDIR}/.gdbm_buildlink_done
GDBM_BUILDLINK_TARGETS=		link-gdbm-headers
GDBM_BUILDLINK_TARGETS+=	link-gdbm-libs
BUILDLINK_TARGETS+=		${GDBM_BUILDLINK_COOKIE}

pre-configure: ${GDBM_BUILDLINK_COOKIE}

${GDBM_BUILDLINK_COOKIE}: ${GDBM_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${GDBM_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-gdbm-headers:
	@${ECHO} "Linking gdbm headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${GDBM_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
        done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-gdbm-libs:
	@${ECHO} "Linking gdbm libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${GDBM_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# GDBM_BUILDLINK_MK
