# $NetBSD: buildlink.mk,v 1.1 2001/05/31 22:52:17 jlam Exp $
#
# This Makefile fragment is included by packages that use rpc2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define RPC2_REQD to the version of rpc2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(RPC2_BUILDLINK_MK)
RPC2_BUILDLINK_MK=	# defined

.include "../../devel/lwp/buildlink.mk"

RPC2_REQD?=		1.10
DEPENDS+=		rpc2>=${RPC2_REQD}:../../devel/rpc2

RPC2_HEADERS=		${LOCALBASE}/include/rpc2/*
RPC2_LIBS=		${LOCALBASE}/lib/libfail.*
RPC2_LIBS+=		${LOCALBASE}/lib/librpc2.*
RPC2_LIBS+=		${LOCALBASE}/lib/libse.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-rpc2-headers
BUILDLINK_TARGETS+=	link-rpc2-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-rpc2-headers:
	@${ECHO} "Linking rpc2 headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/rpc2
	@${RM} -f ${BUILDLINK_INCDIR}/rpc2/*
	@for inc in ${RPC2_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/rpc2/`${BASENAME} $${inc}`;	\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
        done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-rpc2-libs:
	@${ECHO} "Linking rpc2 libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${RPC2_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# RPC2_BUILDLINK_MK
