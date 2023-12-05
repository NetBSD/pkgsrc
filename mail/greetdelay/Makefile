# $NetBSD: Makefile,v 1.11 2023/12/05 17:07:51 schmonz Exp $

DISTNAME=	greetdelay-0.03
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20081025100202/http://alkemio.org/software/greetdelay/
COMMENT=	Introduces a small delay before an SMTP greeting

BUILD_TARGET=	greetdelay

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greetdelay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greetdelay.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
