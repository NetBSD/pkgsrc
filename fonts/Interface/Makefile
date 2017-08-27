# $NetBSD: Makefile,v 1.1 2017/08/27 19:24:59 wiz Exp $

DISTNAME=	Interface-1.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=rsms/}
EXTRACT_SUFX=	.zip
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	interface

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rsms.me/interface/
COMMENT=	Font for highly legible text on computer screens
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/"Interface (OTF)"/*.otf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
