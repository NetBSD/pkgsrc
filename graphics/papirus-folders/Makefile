# $NetBSD: Makefile,v 1.3 2019/06/20 13:25:38 nia Exp $

DISTNAME=	papirus-folders-1.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=PapirusDevelopmentTeam/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/PapirusDevelopmentTeam/papirus-folders
COMMENT=	Script for modifying the Papirus Icon Theme
LICENSE=	mit

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none
USE_TOOLS+=	bash
NO_BUILD=	yes

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	papirus-icon-theme-[0-9]*:../../graphics/papirus-icon-theme

REPLACE_BASH+=	papirus-folders

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-install
SUBST_MESSAGE.prefix=	Add PREFIX to search path.
SUBST_FILES.prefix+=	papirus-folders
SUBST_SED.prefix+=	-e "s,/usr/local/share:,/usr/local/share:${PREFIX}/share:,g"

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/papirus-folders \
	    ${DESTDIR}${PREFIX}/bin/papirus-folders

.include "../../mk/bsd.pkg.mk"
