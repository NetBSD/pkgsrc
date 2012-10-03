# $NetBSD: Makefile,v 1.7 2012/10/03 18:28:32 asau Exp $

DISTNAME=	un-fonts-extra-1.0.2-080608
PKGNAME=	${DISTNAME:S/fonts-extra/extra-ttf/:S/-0/.200/}
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

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
