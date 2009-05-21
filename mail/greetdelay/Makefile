# $NetBSD: Makefile,v 1.7 2009/05/21 11:16:02 zafer Exp $
#

DISTNAME=	greetdelay-0.03
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://alkemio.org/software/greetdelay/
COMMENT=	Introduces a small delay before an SMTP greeting

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	default

USE_TOOLS+=	nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greetdelay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greetdelay.0 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
	${INSTALL_MAN} ${WRKSRC}/greetdelay.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
