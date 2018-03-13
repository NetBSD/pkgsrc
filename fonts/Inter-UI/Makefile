# $NetBSD: Makefile,v 1.1 2018/03/13 21:19:52 bsiegert Exp $

VERSION=	2.5
DISTNAME=	Inter-UI-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	https://github.com/rsms/inter/releases/download/v${VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rsms.me/inter/
COMMENT=	Font for highly legible text on computer screens
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/"Inter UI (OTF)"/*.otf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
