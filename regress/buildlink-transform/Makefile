# $NetBSD: Makefile,v 1.5 2004/08/28 02:35:41 jlam Exp $
#
# Run many buildlink transform tests in a single regression test to avoid
# having to keep creating the wrapper scripts over and over again.
#
DISTNAME=	regress-buildlink-transform-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
COMMENT=	test buildlink wrapper transformation

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
NO_PACKAGE=	yes

REGRESS_ENV=		PATH=${PATH}
#REGRESS_ENV+=		WRAPPER_DEBUG=yes

# Create a "regress" script in the wrapper directory that just echoes its
# arguments.
#
REGRESS=		${ECHO}
_BLNK_WRAPPEES+=	REGRESS
_ALIASES.REGRESS=	regress

post-buildlink:
	@${RM} ${BUILDLINK_DIR}/bin/${REGRESS}

.PHONY: regress do-regress

regress: buildlink
	@cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} do-regress PKG_PHASE=buildlink

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
