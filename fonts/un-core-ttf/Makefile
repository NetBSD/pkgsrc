# $NetBSD: Makefile,v 1.9 2015/07/04 16:18:34 joerg Exp $

DISTNAME=	un-fonts-core-1.0.2-080608
PKGNAME=	${DISTNAME:S/fonts-core/core-ttf/:S/-0/.200/}
PKGREVISION=	1
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/frs/download.php/4695/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://kldp.net/projects/unfonts/
COMMENT=	Core set of Un Korean TrueType fonts

CONFLICTS+=	un-ttf-[0-9]*

WRKSRC=		${WRKDIR}/un-fonts
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
