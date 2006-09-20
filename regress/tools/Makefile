# $NetBSD: Makefile,v 1.5 2006/09/20 07:39:54 rillig Exp $
#

DISTNAME=	# not applicable
PKGNAME=	regress-tools-1.1
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rillig@NetBSD.org
COMMENT=	Test whether the TOOLS do what I expect

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
REGRESS_TESTS=	awk sed sort tr
USE_TOOLS+=	awk sed sort tr

do-build:
.for t in ${REGRESS_TESTS}
	${_PKG_SILENT}${_PKG_DEBUG}set -e; cd ${WRKSRC:Q};		\
	${ECHO_MSG} "Running testsuite "${t:Q};				\
	${SH} ${FILESDIR:Q}/${t:Q}-test.sh
.endfor

.include "../../mk/bsd.pkg.mk"
