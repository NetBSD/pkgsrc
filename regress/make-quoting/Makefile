# $NetBSD: Makefile,v 1.8 2008/03/04 11:02:25 rillig Exp $
#

DISTNAME=	regress-make-1.0
CATEGORIES=	regress
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test Makefile quoting and make(1) bugs

NUM_MAKE_VERSION=	${MAKE_VERSION:C/[^0-9]//g}

.include "../../mk/bsd.prefs.mk"

REGRESS_TESTS=	# none

# Has been fixed somewhere in 2005.
.if ${NUM_MAKE_VERSION} < 20050101
REGRESS_TESTS+=	bug1
.endif

REGRESS_TESTS+=	bug2

# Has been fixed somewhere in 2006.
.if ${NUM_MAKE_VERSION} < 20060101
REGRESS_TESTS+=	continue
.endif

REGRESS_TESTS+=	dblquote for ltarget nestfor

.if ${NUM_MAKE_VERSION} < 20060629
REGRESS_TESTS+=	newline
.endif

# The NetBSD 3.0 /bin/sh is buggy.
.if !(${OPSYS} == "NetBSD" && !empty(OS_VERSION:M3.0*))
REGRESS_TESTS+=	quoting
.endif

REGRESS_TESTS+=	sglquote vtarget

WRKSRC=		${WRKDIR}
USE_TOOLS+=	diff printf

do-build: do-regress
	@${DO_NADA}

do-regress:
	@printf "Testing bmake(1) version %s\\n" ${NUM_MAKE_VERSION:Q}""
.for t in ${REGRESS_TESTS}
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "Running testcase "${t:Q};				\
	${MAKE} ${MAKEFLAGS} -s -f ${FILESDIR:Q}/${t:Q}.mk		\
	| diff - ${FILESDIR:Q}/${t:Q}.out
.endfor

.include "../../mk/bsd.pkg.mk"
