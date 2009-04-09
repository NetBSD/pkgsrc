# $NetBSD: Makefile,v 1.9 2009/04/09 00:47:13 joerg Exp $
#

DISTNAME=	# not applicable
PKGNAME=	regress-tools-1.2
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test whether the TOOLS do what I expect

WRKSRC=		${WRKDIR}
REGRESS_TESTS=	awk sed sh sort tar tr
USE_TOOLS+=	awk sed sh sort tar tr

do-build:
.for t in ${REGRESS_TESTS}
	${_PKG_SILENT}${_PKG_DEBUG}set -e; cd ${WRKSRC:Q};		\
	${ECHO_MSG} "Running testsuite "${t:Q};				\
	${SH} ${FILESDIR:Q}/${t:Q}-test.sh
.endfor

.include "../../mk/bsd.pkg.mk"
