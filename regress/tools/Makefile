# $NetBSD: Makefile,v 1.2 2005/11/19 22:03:54 rillig Exp $
#

DISTNAME=	regress-tools-1.0
CATEGORIES=	regress
DISTFILES=	# empty

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test whether the TOOLS do what I expect

WRKSRC=		${WRKDIR}
REGRESS_TESTS=	awk
USE_TOOLS+=	awk

do-build:
.for t in ${REGRESS_TESTS}
	@${_PKG_SILENT}${_PKG_DEBUG}set -e; cd ${WRKSRC:Q};		\
	${ECHO_MSG} "Running testsuite "${t:Q};				\
	${SH} ${FILESDIR:Q}/${t:Q}-test.sh
.endfor

.include "../../mk/bsd.pkg.mk"
