# $NetBSD: Makefile,v 1.2 2018/06/03 22:12:13 youri Exp $

GHCOMMIT=	13cba0d7d6abf286047c3d551d84db415cc7ea52
DISTNAME=	${GHCOMMIT}
PKGNAME=	slim-themes-20180214
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=adi1090x/slim_themes/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/adi1090x/slim_themes
COMMENT=	Beautiful Collection Of SLiM Themes

NO_BUILD=	YES
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/slim_themes-${GHCOMMIT}/themes

INSTALLATION_DIRS+=	share/slim/themes

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm * ${DESTDIR}${PREFIX}/share/slim/themes/

.include "../../mk/bsd.pkg.mk"
