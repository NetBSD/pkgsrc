# $NetBSD: buildlink.mk,v 1.2 2001/05/24 08:58:25 jlam Exp $
#
# This Makefile fragment is included by packages that use readline().
#
# If readline() is not present in the base system through libedit, then a
# dependency on devel/readline is added, the appropriate headers are linked
# into ${BUILDLINK_INCDIR} (${WRKDIR}/include), and the appropriate libraries
# are linked into ${BUILDLINK_LIBDIR} (${WRKDIR}/lib).
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_GNU_READLINE to force use of GNU readline.
# (2) Optionally define READLINE_REQD to the version of GNU readline desired.
# (3) Include this Makefile fragment in the package Makefile,
# (4) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (5) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (6) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (7) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.
#
# NOTE:	You may need to do some more work to get libedit recognized over
#	libreadline, especially by GNU configure scripts.

READLINE_REQD?=		2.2

.if defined(USE_GNU_READLINE)
READLINE_INCDIR=	${LOCALBASE}/include/readline
LIBREADLINE=		${LOCALBASE}/lib/libreadline.a
LIBREADLINE+=		${LOCALBASE}/lib/libreadline.so*
LIBHISTORY=		${LOCALBASE}/lib/libhistory.a
LIBHISTORY+=		${LOCALBASE}/lib/libhistory.so*
DEPENDS+=		readline>=${READLINE_REQD}:../../devel/readline
.else
.if exists(/usr/include/readline.h)
READLINE_H=		/usr/include/readline.h
HISTORY_H=		/usr/include/history.h
LIBREADLINE=		/usr/lib/libedit.a
LIBREADLINE+=		/usr/lib/libedit.so*
LIBHISTORY=		/usr/lib/libedit.a
LIBHISTORY+=		/usr/lib/libedit.so*
HAVE_LIBEDIT_READLINE=	# defined
.elif exists(/usr/include/readline/readline.h)
READLINE_INCDIR=	/usr/include/readline
LIBREADLINE=		/usr/lib/libedit.a
LIBREADLINE+=		/usr/lib/libedit.so*
LIBHISTORY=		/usr/lib/libedit.a
LIBHISTORY+=		/usr/lib/libedit.so*
HAVE_LIBEDIT_READLINE=	# defined
.else
READLINE_INCDIR=	${LOCALBASE}/include/readline
LIBREADLINE=		${LOCALBASE}/lib/libreadline.a
LIBREADLINE+=		${LOCALBASE}/lib/libreadline.so*
LIBHISTORY=		${LOCALBASE}/lib/libhistory.a
LIBHISTORY+=		${LOCALBASE}/lib/libhistory.so*
DEPENDS+=		readline>=${READLINE_REQD}:../../devel/readline
.endif
.endif

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-readline-headers
BUILDLINK_TARGETS+=	link-readline-libs

# This target links the readline and history headers into ${BUILDLINK_INCDIR},
# which should be searched first by the C preprocessor.
#
link-readline-headers:
	@${ECHO} "Linking readline headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} -p ${BUILDLINK_INCDIR}/readline
	@${RM} -f ${BUILDLINK_INCDIR}/readline/*
.if defined(READLINE_INCDIR)
	@for inc in ${READLINE_INCDIR}/*; do				\
		${LN} -sf $${inc} ${BUILDLINK_INCDIR}/readline;		\
	done
.else
	@${LN} -sf ${READLINE_H} ${BUILDLINK_INCDIR}/readline
	@${LN} -sf ${HISTORY_H} ${BUILDLINK_INCDIR}/readline
.endif

# This target links the readline and history libraries into
# ${BUILDLINK_LIBDIR}, which should be searched first by the linker.
#
link-readline-libs:
	@${ECHO} "Linking readline libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} -p ${BUILDLINK_LIBDIR}
	@for lib in ${LIBREADLINE}; do					\
		dest=`${BASENAME} $${lib} | ${SED} "s|libedit|libreadline|"`; \
		${LN} -sf $${lib} ${BUILDLINK_LIBDIR}/$${dest};		\
	done
	@for lib in ${LIBHISTORY}; do					\
		dest=`${BASENAME} $${lib} | ${SED} "s|libedit|libhistory|"`; \
		${LN} -sf $${lib} ${BUILDLINK_LIBDIR}/$${dest};		\
	done
