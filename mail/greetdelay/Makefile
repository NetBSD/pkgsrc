# $NetBSD: Makefile,v 1.4 2007/01/30 22:09:06 schmonz Exp $
#

DISTNAME=	greetdelay-0.03
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://alkemio.org/software/greetdelay/
COMMENT=	Introduces a small delay before an SMTP greeting

BUILD_TARGET=	default

USE_TOOLS+=	nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC}; \
	cp greetdelay ${PREFIX}/bin; \
	cp greetdelay.0 ${PREFIX}/${PKGMANDIR}/cat1; \
	cp greetdelay.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
