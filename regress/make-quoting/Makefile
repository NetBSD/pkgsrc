# $NetBSD: Makefile,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#

DISTNAME=	regress-make-1.0
CATEGORIES=	regress
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test Makefile quoting

REGRESS_TESTS=	continue dblquote for ltarget nestfor quoting sglquote	\
	vtarget

do-extract:
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${MKDIR} ${WRKSRC:Q}

do-build:
.for t in ${REGRESS_TESTS}
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "Running testcase "${t:Q};				\
	${MAKE} ${MAKEFLAGS} -s -f ${FILESDIR:Q}/${t:Q}.mk		\
	| diff - ${FILESDIR:Q}/${t:Q}.out
.endfor

.include "../../mk/bsd.pkg.mk"
