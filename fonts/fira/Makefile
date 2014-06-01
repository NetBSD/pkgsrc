# $NetBSD: Makefile,v 1.2 2014/06/01 16:35:33 wiz Exp $

DISTNAME=	fira-${VERSION}
VERSION=	3105
PKGNAME=	${DISTNAME:C/3/3./}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://dev.carrois.com/wordpress/wp-content/uploads/downloads/fira_${VERSION}/
EXTRACT_SUFX=	.zip
DISTFILES=	FiraSans${VERSION}.zip FiraMono${VERSION}.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dev.carrois.com/fira-3-1/
COMMENT=	Mozilla's font for Firefox OS
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}

FONTS_DIRS.otf+=	share/fonts/X11/OTF
INSTALLATION_DIRS+=	${FONTS_DIRS.otf}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/Fira*/OTF/*.otf ${DESTDIR}${PREFIX}/${FONTS_DIRS.otf}

.include "../../mk/bsd.pkg.mk"
