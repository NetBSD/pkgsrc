# $NetBSD: Makefile,v 1.6 2006/06/29 13:35:18 rillig Exp $
#

DISTNAME=	regress-make-1.0
CATEGORIES=	regress
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test Makefile quoting and make(1) bugs

REGRESS_TESTS=	bug1 bug2 continue dblquote for ltarget nestfor newline
REGRESS_TESTS+=	quoting sglquote vtarget

WRKSRC=		${WRKDIR}

do-build: do-regress
	@${DO_NADA}

do-regress:
.for t in ${REGRESS_TESTS}
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "Running testcase "${t:Q};				\
	${MAKE} ${MAKEFLAGS} -s -f ${FILESDIR:Q}/${t:Q}.mk		\
	| diff - ${FILESDIR:Q}/${t:Q}.out
.endfor

.include "../../mk/bsd.pkg.mk"
