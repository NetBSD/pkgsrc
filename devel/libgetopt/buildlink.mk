# $NetBSD: buildlink.mk,v 1.4 2001/05/25 04:49:15 jlam Exp $
#
# This Makefile fragment is included by packages that use getopt_long().
#
# If getopt_long() is not present in the base system, then a dependency
# on devel/libgetopt is added, and the appropriate headers are linked
# into ${BUILDLINK_INCDIR} (${WRKDIR}/include).
#
# To use this Makefile fragment, simply:
#
# (1) Include this Makefile fragment in the package Makefile,
# (2) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (3) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path.
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if exists(/usr/include/getopt.h)
GETOPT_H=		/usr/include/getopt.h
.else
GETOPT_H=		${LOCALBASE}/include/getopt.h
LIBGETOPT=		${LOCALBASE}/lib/libgetopt.a
LIBGETOPT+=		${LOCALBASE}/lib/libgetopt_pic.a
LIBGETOPT+=		${LOCALBASE}/lib/libgetopt.so*
DEPENDS+=		libgetopt>=1.3:../../devel/libgetopt
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		LIBS="${LIBS}"
LIBS+=			-lgetopt
.endif
.endif

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-getopt-headers
BUILDLINK_TARGETS+=	link-getopt-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
# 
link-getopt-headers:
	@${ECHO} "Linking getopt headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@${RM} -f ${BUILDLINK_INCDIR}/getopt.h
	@${LN} -sf ${GETOPT_H} ${BUILDLINK_INCDIR}/getopt.h

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-getopt-libs:
	@${ECHO} "Linking getopt libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
.if defined(LIBGETOPT)
	@for lib in ${LIBGETOPT}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done
.endif
