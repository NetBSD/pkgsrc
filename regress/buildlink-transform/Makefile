# $NetBSD: Makefile,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

DISTNAME=	regress-buildlink-transform-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
COMMENT=	test buildlink wrapper transformation

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
NO_PACKAGE=	yes

REGRESS_ENV=		PATH=${PATH}
REGRESS_ENV+=		WRAPPER_DEBUG=yes

REGRESS=		${ECHO}
_WRAPPEES+=		REGRESS
_WRAP_ALIASES.REGRESS=	regress

post-wrapper:
	@${RM} ${WRAPPER_BINDIR}/${REGRESS}

.PHONY: regress do-regress

regress: wrapper
	@cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} do-regress PKG_PHASE=wrapper

do-regress:
	@${DO_NADA}

TEST_RESULT=	runtest=`${SETENV} ${REGRESS_ENV} regress $$test`;	\
		${ECHO} "(${.TARGET}) saw:      $$test";		\
		${ECHO} "(${.TARGET}) got:      $$runtest";		\
		${ECHO} "(${.TARGET}) expected: $$expected";		\
		case $$runtest in					\
		$$expected)	;;					\
		*)		exit 1 ;;				\
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
