# $NetBSD: Makefile,v 1.8 2012/03/08 01:07:39 joerg Exp $
#

DISTNAME=	greetdelay-0.03
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://alkemio.org/software/greetdelay/
COMMENT=	Introduces a small delay before an SMTP greeting

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	greetdelay

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greetdelay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greetdelay.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
