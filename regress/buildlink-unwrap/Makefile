# $NetBSD: Makefile,v 1.1.1.1 2004/08/28 06:17:21 jlam Exp $

DISTNAME=	regress-buildlink-unwrap-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
COMMENT=	test buildlink unwrapping of text files

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=	yes
EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_INSTALL=	yes
NO_PACKAGE=	yes

# Remove GCC optimization options.
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*

# Convert "-lreadline" into "-ledit -ltermcap -lm".
BUILDLINK_TRANSFORM+=	l:readline:edit:termcap:m

REGRESS_UNWRAP_SED=							\
	-e "s|@PREFIX@|${PREFIX}|g"					\
	-e "s|@COMPILER_RPATH_FLAG@|${COMPILER_RPATH_FLAG}|g"

do-build:
	@${FIND} ${TEST_DIR} -name "*.sh" -print |			\
	while read file; do						\
		dest=`${BASENAME} $$file .sh`;				\
		${SED} ${REGRESS_UNWRAP_SED} $$file > ${WRKSRC}/$$dest;	\
		${CHMOD} +x ${WRKSRC}/$$dest;				\
	done

.PHONY: regress do-regress

regress: build do-regress

do-regress:
	@${DO_NADA}

TEST_RESULT=	PATH="${WRKSRC}:${PATH}";				\
		runtest=`$$test`;					\
		${ECHO} "(${.TARGET}) ran:      $$test";		\
		${ECHO} "(${.TARGET}) got:      $$runtest";		\
		${ECHO} "(${.TARGET}) expected: $$expected";		\
		case $$runtest in					\
		$$expected)						\
			${ECHO} "(${.TARGET}) result:   PASS";		\
			;;						\
		*)							\
			${ECHO} "(${.TARGET}) result:   FAIL";		\
			exit 1;						\
			;;						\
		esac

TEST_DIR=	${.CURDIR}/tests

# If RUNTESTS is defined, then just run those tests, otherwise run them all.
.if defined(RUNTESTS)
TEST_MAKEFILES=	${RUNTESTS:S/^/${TEST_DIR}\//:S/$/.mk/}
.else
TEST_MAKEFILES!= \
	${FIND} ${TEST_DIR} -name "*.mk" -print || ${ECHO} "none"
.endif

.for _mkfile_ in ${TEST_MAKEFILES}
.  if exists(${_mkfile_})
.    include "${_mkfile_}"
.  endif
.endfor

.include "../../mk/bsd.pkg.mk"
