# $NetBSD: Makefile,v 1.2 2008/03/04 11:02:25 rillig Exp $
#

DISTNAME=	barrier-1.0
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tests whether pkgsrc barriers work as expected

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

do-build:
	perl -e 'print "hello\n";'

.include "../../mk/bsd.pkg.mk"
