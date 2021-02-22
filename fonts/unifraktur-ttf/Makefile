# $NetBSD: Makefile,v 1.1 2021/02/22 20:49:20 wiz Exp $

DISTNAME=	UnifrakturMaguntia.2017-03-19
PKGNAME=	unifraktur-ttf-20170319
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unifraktur/}
EXTRACT_SUFX=	.zip

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://unifraktur.sourceforge.net/
COMMENT=	Modification of the Berthold Mainzer Fraktur font from Peter Wiegel
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/UnifrakturMaguntia.ttf ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
