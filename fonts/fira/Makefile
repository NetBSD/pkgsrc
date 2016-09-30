# $NetBSD: Makefile,v 1.3 2016/09/30 14:29:00 wiz Exp $

DISTNAME=	fira-4.202
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla/}
GITHUB_PROJECT=	Fira

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mozilla.github.io/Fira/
COMMENT=	Mozilla's font for Firefox OS
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none

WRKSRC=		${WRKDIR}/${DISTNAME:S/f/F/}

FONTS_DIRS.otf+=	share/fonts/X11/OTF
INSTALLATION_DIRS+=	${FONTS_DIRS.otf}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/otf/*.otf ${DESTDIR}${PREFIX}/${FONTS_DIRS.otf}

.include "../../mk/bsd.pkg.mk"
