# $NetBSD: buildlink.mk,v 1.3 2001/05/25 04:49:16 jlam Exp $
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
_NEED_GNU_READLINE=	YES
.elif exists(/usr/include/readline.h) || \
      exists(/usr/include/readline/readline.h)
_NEED_GNU_READLINE=	NO
.else
_NEED_GNU_READLINE=	YES
.endif

.if ${_NEED_GNU_READLINE} == "YES"
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
.else # exists(/usr/include/readline/readline.h)
READLINE_INCDIR=	/usr/include/readline
LIBREADLINE=		/usr/lib/libedit.a
LIBREADLINE+=		/usr/lib/libedit.so*
LIBHISTORY=		/usr/lib/libedit.a
LIBHISTORY+=		/usr/lib/libedit.so*
HAVE_LIBEDIT_READLINE=	# defined
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
	@${MKDIR} ${BUILDLINK_INCDIR}/readline
	@${RM} -f ${BUILDLINK_INCDIR}/readline/*
.if defined(READLINE_INCDIR)
	@for inc in ${READLINE_INCDIR}/*; do				\
		dest=${BUILDLINK_INCDIR}/readline/`${BASENAME} $${inc}`; \
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done
.else
	@for inc in ${READLINE_H} ${HISTORY_H}; do			\
		dest=${BUILDLINK_INCDIR}/readline/`${BASENAME} $${inc}`; \
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done
.endif

# This target links the readline and history libraries into
# ${BUILDLINK_LIBDIR}, which should be searched first by the linker.
#
link-readline-libs:
	@${ECHO} "Linking readline libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${LIBREADLINE}; do					\
		name=`${BASENAME} $${lib} | ${SED} "s|libedit|libreadline|"`; \
		dest=${BUILDLINK_LIBDIR}/$${name};			\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done
	@for lib in ${LIBHISTORY}; do					\
		name=`${BASENAME} $${lib} | ${SED} "s|libedit|libhistory|"`; \
		dest=${BUILDLINK_LIBDIR}/$${name};			\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done
