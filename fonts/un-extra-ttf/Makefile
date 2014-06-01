# $NetBSD: Makefile,v 1.8 2014/06/01 16:35:37 wiz Exp $

DISTNAME=	un-fonts-extra-1.0.2-080608
PKGNAME=	${DISTNAME:S/fonts-extra/extra-ttf/:S/-0/.200/}
PKGREVISION=	1
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/frs/download.php/4696/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://kldp.net/projects/unfonts/
COMMENT=	Extra set of Un Korean TrueType fonts

CONFLICTS+=	un-ttf-[0-9]*

WRKSRC=		${WRKDIR}/un-fonts
USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
