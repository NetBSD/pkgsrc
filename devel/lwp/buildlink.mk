# $NetBSD: buildlink.mk,v 1.2 2001/06/09 15:21:03 wiz Exp $
#
# This Makefile fragment is included by packages that use lwp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define LWP_REQD to the version of lwp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(LWP_BUILDLINK_MK)
LWP_BUILDLINK_MK=	# defined

LWP_REQD?=		1.6
DEPENDS+=		lwp>=${LWP_REQD}:../../devel/lwp

LWP_HEADERS=		${LOCALBASE}/include/lwp/*
LWP_LIBS=		${LOCALBASE}/lib/liblwp.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-lwp-headers
BUILDLINK_TARGETS+=	link-lwp-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-lwp-headers:
	@${ECHO} "Linking lwp headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/lwp
	@${RM} -f ${BUILDLINK_INCDIR}/lwp/*
	@for inc in ${LWP_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/lwp/`${BASENAME} $${inc}`;	\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-lwp-libs:
	@${ECHO} "Linking lwp libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${LWP_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# LWP_BUILDLINK_MK
