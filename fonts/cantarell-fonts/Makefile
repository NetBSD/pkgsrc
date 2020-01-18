# $NetBSD: Makefile,v 1.9 2020/01/18 23:31:01 rillig Exp $
#

DISTNAME=	cantarell-fonts-0.111
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cantarell-fonts/0.111/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/CantarellFonts
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
	${INSTALL_DATA} ${WRKSRC}/prebuilt/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
