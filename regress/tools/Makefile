# $NetBSD: Makefile,v 1.11 2019/03/22 20:56:16 rillig Exp $
#

DISTNAME=	# not applicable
PKGNAME=	regress-tools-1.2
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test whether the TOOLS do what I expect
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
PLIST_SRC=	# none
REGRESS_TESTS+=	logging
REGRESS_TESTS+=	awk sed sh sort tar tr
USE_TOOLS+=	awk sed sh sort tar tr

do-build:
.for t in ${REGRESS_TESTS}
	${RUN} cd ${WRKSRC};						\
	${ECHO_MSG} "Running testsuite "${t:Q};				\
	${SH} ${FILESDIR}/${t:Q}-test.sh
.endfor

.include "../../mk/bsd.pkg.mk"
