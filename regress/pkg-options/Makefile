# $NetBSD: Makefile,v 1.1.1.1 2005/05/16 00:09:03 rillig Exp $
#

DISTNAME=	regress-pkg-options-1.0
CATEGORIES=	regress
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test bsd.options.mk framework

REGRESS_TESTS=	simple

do-test:
.for t in ${REGRESS_TESTS}
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "Running testcase "${t:Q};				\
	${MAKE} ${MAKEFLAGS} -s -f ${FILESDIR:Q}/${t:Q}.mk test		\
	| diff - ${FILESDIR:Q}/${t:Q}.out
.endfor

.include "../../mk/bsd.pkg.mk"
