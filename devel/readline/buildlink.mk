# $NetBSD: buildlink.mk,v 1.9 2001/06/11 01:59:35 jlam Exp $
#
# This Makefile fragment is included by packages that use readline().
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_GNU_READLINE to force use of GNU readline.
# (2) Optionally define READLINE_REQD to the version of GNU readline desired.
# (3) Include this Makefile fragment in the package Makefile,
# (4) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
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

READLINE_BUILDLINK_COOKIE=	${BUILDLINK_DIR}/.readline_buildlink_done
READLINE_BUILDLINK_TARGETS=	link-readline-headers
.if defined(HAVE_LIBEDIT_READLINE) && defined(USE_LIBTOOL)
READLINE_BUILDLINK_TARGETS+=	editline-libtool-archive
.endif
READLINE_BUILDLINK_TARGETS+=	link-readline-libs
BUILDLINK_TARGETS+=		${READLINE_BUILDLINK_COOKIE}

pre-configure: ${READLINE_BUILDLINK_COOKIE}

${READLINE_BUILDLINK_COOKIE}: ${READLINE_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${READLINE_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_DIR}/include, which should
# be searched first by the C preprocessor.
#
link-readline-headers:
	@${ECHO} "Linking readline headers into ${BUILDLINK_DIR}/include."
	@${MKDIR} ${BUILDLINK_DIR}/include/readline
	@${RM} -f ${BUILDLINK_DIR}/include/readline/*
	@for inc in ${READLINE_HEADERS}; do				\
		dest=${BUILDLINK_DIR}/include/readline/`${BASENAME} $${inc}`; \
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_DIR}/lib, which should
# be searched first by the linker.
#
link-readline-libs:
	@${ECHO} "Linking readline libraries into ${BUILDLINK_DIR}/lib."
	@${MKDIR} ${BUILDLINK_DIR}/lib
	@for lib in ${READLINE_LIBS}; do				\
		name=`${BASENAME} $${lib} | ${SED} "s|libedit|libreadline|"`; \
		dest=${BUILDLINK_DIR}/lib/$${name};			\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done
	@for lib in ${HISTORY_LIBS}; do					\
		name=`${BASENAME} $${lib} | ${SED} "s|libedit|libhistory|"`; \
		dest=${BUILDLINK_DIR}/lib/$${name};			\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.if defined(HAVE_LIBEDIT_READLINE) && defined(USE_LIBTOOL)
editline-libtool-archive:
	@${ECHO} "Creating editline libtool archive in ${BUILDLINK_DIR}/lib."
	@${MKDIR} ${BUILDLINK_DIR}/lib
	@cd /usr/lib; for lib in libedit.so.*.*; do			\
		major=`${ECHO} $$lib | ${SED} "s|.*\.so\.||;s|\..*||"`;	\
		minor=`${ECHO} $$lib | ${SED} "s|.*\.||"`;		\
	done;								\
	cd ${BUILDLINK_DIR}/lib;					\
	${LIBTOOL} --quiet --mode=link ${CC} -o libedit.la		\
		-version-info $$major:$$minor -rpath /usr/lib;		\
	${LIBTOOL} --quiet --mode=install ${CP} libedit.la		\
		${BUILDLINK_DIR}/lib 2>/dev/null;			\
	${RM} -f libedit.a;						\
	${RM} -f libreadline.la;					\
	${LN} -sf libedit.la libreadline.la
.endif

.include "../../mk/bsd.buildlink.mk"

.endif	# READLINE_BUILDLINK_MK
