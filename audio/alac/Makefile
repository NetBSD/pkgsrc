# $NetBSD: Makefile,v 1.4 2023/08/30 21:46:32 js Exp $

DISTNAME=	alac_decoder-0.2.0
PKGNAME=	${DISTNAME:S/_decoder//}
CATEGORIES=	audio
MASTER_SITES=	https://web.archive.org/web/20150510210401if_/http://craz.net/programs/itunes/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20150319040222/craz.net/programs/itunes/alac.html
COMMENT=	Basic decoder for Apple Lossless Audio Codec files (ALAC)
LICENSE=	mit

WRKSRC=		${WRKDIR}/alac_decoder
BUILD_TARGET=	alac

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alac ${DESTDIR}${PREFIX}/bin/alac

.include "../../mk/bsd.pkg.mk"
