# $NetBSD: Makefile,v 1.1 2014/07/17 14:52:08 ryoon Exp $

DISTNAME=	SourceHanSansOTF-1.000
PKGNAME=	${DISTNAME:S/SourceHanSansOTF/sourcehansans-fonts/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=source-han-sans.adobe/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://example.com/
COMMENT=	Set of Pan-CJK fonts from Adobe
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_X11BASE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF

INSTALL_FONTS=	SourceHanSans-Bold.otf \
		SourceHanSans-ExtraLight.otf \
		SourceHanSans-Heavy.otf \
		SourceHanSans-Light.otf \
		SourceHanSans-Medium.otf \
		SourceHanSans-Normal.otf \
		SourceHanSans-Regular.otf

do-install:
.for i in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
