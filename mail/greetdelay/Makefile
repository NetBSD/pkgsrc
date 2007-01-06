# $NetBSD: Makefile,v 1.2 2007/01/06 02:52:31 schmonz Exp $
#

DISTNAME=	greetdelay-0.02
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://alkemio.org/software/greetdelay/
COMMENT=	Introduces a small delay before an SMTP greeting

BUILD_TARGET=	default

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC}; \
	cp greetdelay ${PREFIX}/bin; \
	cp greetdelay.0 ${PREFIX}/${PKGMANDIR}/cat1; \
	cp greetdelay.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
