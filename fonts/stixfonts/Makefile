# $NetBSD: Makefile,v 1.1 2022/04/14 09:01:30 wiz Exp $

DISTNAME=	stixfonts-2.13b171
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=stipub/}
EXTRACT_SUFX=	.tar.gz
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.stixfonts.org/
COMMENT=	OpenType Unicode maths fonts
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/OTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/doc/${PKGNAME}

SUPERSEDES=	stix-otf-[0-9]*
CONFLICTS=	stix-otf-[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/archive/STIXv2.0.2/docs/*.pdf \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
