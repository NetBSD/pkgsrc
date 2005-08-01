# $NetBSD: Makefile,v 1.4 2005/08/01 00:40:30 rillig Exp $
#

DISTNAME=	regress-make-1.0
CATEGORIES=	regress
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test Makefile quoting and make(1) bugs

REGRESS_TESTS=	continue dblquote for ltarget nestfor quoting sglquote	\
	vtarget bug1 bug2

do-regress:
.for t in ${REGRESS_TESTS}
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "Running testcase "${t:Q};				\
	${MAKE} ${MAKEFLAGS} -s -f ${FILESDIR:Q}/${t:Q}.mk		\
	| diff - ${FILESDIR:Q}/${t:Q}.out
.endfor

.include "../../mk/bsd.pkg.mk"
