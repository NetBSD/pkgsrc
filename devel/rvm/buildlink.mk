# $NetBSD: buildlink.mk,v 1.1 2001/05/31 22:53:48 jlam Exp $
#
# This Makefile fragment is included by packages that use rvm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define RVM_REQD to the version of rvm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(RVM_BUILDLINK_MK)
RVM_BUILDLINK_MK=	# defined

.include "../../devel/lwp/buildlink.mk"

RVM_REQD?=		1.3
DEPENDS+=		rvm>=${RVM_REQD}:../../devel/rvm

RVM_HEADERS=		${LOCALBASE}/include/rvm/*
RVM_LIBS=		${LOCALBASE}/lib/librds.*
RVM_LIBS+=		${LOCALBASE}/lib/librdslwp.*
RVM_LIBS+=		${LOCALBASE}/lib/librvm.*
RVM_LIBS+=		${LOCALBASE}/lib/librvmlwp.*
RVM_LIBS+=		${LOCALBASE}/lib/libseg.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-rvm-headers
BUILDLINK_TARGETS+=	link-rvm-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-rvm-headers:
	@${ECHO} "Linking rvm headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/rvm
	@${RM} -f ${BUILDLINK_INCDIR}/rvm/*
	@for inc in ${RVM_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/rvm/`${BASENAME} $${inc}`;	\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
        done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-rvm-libs:
	@${ECHO} "Linking rvm libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${RVM_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# RVM_BUILDLINK_MK
