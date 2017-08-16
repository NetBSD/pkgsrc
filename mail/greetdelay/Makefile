# $NetBSD: Makefile,v 1.10 2017/08/16 20:45:40 wiz Exp $
#

DISTNAME=	greetdelay-0.03
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	schmonz@NetBSD.org
#HOMEPAGE=	http://alkemio.org/software/greetdelay/
COMMENT=	Introduces a small delay before an SMTP greeting

BUILD_TARGET=	greetdelay

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greetdelay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greetdelay.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
