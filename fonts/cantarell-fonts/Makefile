# $NetBSD: Makefile,v 1.6 2016/06/18 07:39:04 mef Exp $
#

DISTNAME=	cantarell-fonts-0.0.24
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cantarell-fonts/0.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/CantarellFonts
COMMENT=	Contemporary Humanist sans serif font designed for on-screen reading
LICENSE=	ofl-v1.1

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF

INSTALL_FONTS=		Cantarell-Bold.otf \
			Cantarell-Regular.otf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/otf/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
