# $NetBSD: buildlink.mk,v 1.7 2001/06/05 22:15:01 jlam Exp $
#
# This Makefile fragment is included by packages that use readline().
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

.if !defined(READLINE_BUILDLINK_MK)
READLINE_BUILDLINK_MK=	# defined

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
DEPENDS+=		readline>=${READLINE_REQD}:../../devel/readline
READLINE_HEADERS=	${LOCALBASE}/include/readline/*
READLINE_LIBS=		${LOCALBASE}/lib/libreadline.*
HISTORY_LIBS+=		${LOCALBASE}/lib/libhistory.*
.else
.if exists(/usr/include/readline.h)
HAVE_LIBEDIT_READLINE=	# defined
READLINE_HEADERS=	/usr/include/readline.h
READLINE_HEADERS+=	/usr/include/history.h
READLINE_LIBS=		/usr/lib/libedit.*
HISTORY_LIBS=		/usr/lib/libedit.*
.else # exists(/usr/include/readline/readline.h)
HAVE_LIBEDIT_READLINE=	# defined
READLINE_HEADERS=	/usr/include/readline/*
READLINE_LIBS=		/usr/lib/libedit.*
HISTORY_LIBS=		/usr/lib/libedit.*
.endif
.endif

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-readline-headers
.if defined(HAVE_LIBEDIT_READLINE) && defined(USE_LIBTOOL)
BUILDLINK_TARGETS+=	editline-libtool-archive
.endif
BUILDLINK_TARGETS+=	link-readline-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-readline-headers:
	@${ECHO} "Linking readline headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/readline
	@${RM} -f ${BUILDLINK_INCDIR}/readline/*
	@for inc in ${READLINE_HEADERS}; do				\
		dest=${BUILDLINK_INCDIR}/readline/`${BASENAME} $${inc}`; \
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-readline-libs:
	@${ECHO} "Linking readline libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${READLINE_LIBS}; do				\
		name=`${BASENAME} $${lib} | ${SED} "s|libedit|libreadline|"`; \
		dest=${BUILDLINK_LIBDIR}/$${name};			\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done
	@for lib in ${HISTORY_LIBS}; do					\
		name=`${BASENAME} $${lib} | ${SED} "s|libedit|libhistory|"`; \
		dest=${BUILDLINK_LIBDIR}/$${name};			\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.if defined(HAVE_LIBEDIT_READLINE) && defined(USE_LIBTOOL)
editline-libtool-archive:
	@${ECHO} "Creating editline libtool archive in ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@cd /usr/lib; for lib in libedit.so.*.*; do			\
		major=`${ECHO} $$lib | ${SED} "s|.*\.so\.||;s|\..*||"`;	\
		minor=`${ECHO} $$lib | ${SED} "s|.*\.||"`;		\
	done;								\
	cd ${BUILDLINK_LIBDIR};						\
	${LIBTOOL} --quiet --mode=link ${CC} -o libedit.la		\
		-version-info $$major:$$minor -rpath /usr/lib;		\
	${LIBTOOL} --quiet --mode=install ${CP} libedit.la		\
		${BUILDLINK_LIBDIR} 2>/dev/null;			\
	${RM} -f libedit.a;						\
	${RM} -f libreadline.la;					\
	${LN} -sf libedit.la libreadline.la
.endif

.endif	# READLINE_BUILDLINK_MK
