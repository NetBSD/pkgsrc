# $NetBSD: Makefile,v 1.1 2019/10/20 13:14:46 nia Exp $

DISTNAME=	luv-icon-theme-0.4.9.31
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nitrux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nitrux/luv-icon-theme
COMMENT=	Flat but complex icon theme
LICENSE=	cc-by-sa-v4.0

USE_TOOLS+=	pax
USE_LANGAUGES=	# none
NO_BUILD=	yes

ICON_THEMES=	yes

do-install:
	cd ${WRKSRC}/Luv && \
	    ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/icons/Luv

.include "../../mk/bsd.pkg.mk"
