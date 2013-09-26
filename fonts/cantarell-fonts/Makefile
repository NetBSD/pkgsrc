# $NetBSD: Makefile,v 1.3 2013/09/26 20:48:29 ryoon Exp $
#

DISTNAME=	cantarell-fonts-0.0.15
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cantarell-fonts/0.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/CantarellFonts
COMMENT=	Contemporary Humanist sans serif font designed for on-screen reading
LICENSE=	ofl-v1.1

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF

INSTALL_FONTS=		Cantarell-Bold.otf \
			Cantarell-Regular.otf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/otf/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
