# $NetBSD: Makefile,v 1.2 2021/04/23 16:40:29 nia Exp $

DISTNAME=	minimp3-20210120
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=lieff/}
GITHUB_PROJECT=	minimp3
GITHUB_TAG=	ef9e212fa29bb72d23558da21bb5694fd2d01768

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lieff/minimp3
COMMENT=	Minimalistic MP3 decoder single header library
LICENSE=	cc0-1.0-universal

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/minimp3.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/minimp3_ex.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
