# $NetBSD: Makefile,v 1.2 2005/05/15 22:50:13 rillig Exp $
#

DISTNAME=	regress-make-1.0
CATEGORIES=	regress
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test Makefile quoting

REGRESS_TESTS=	continue dblquote for ltarget nestfor quoting sglquote	\
	vtarget bug1

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
