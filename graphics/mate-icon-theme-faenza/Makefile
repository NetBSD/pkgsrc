# $NetBSD: Makefile,v 1.11 2019/07/21 22:25:02 wiz Exp $

.include "../../meta-pkgs/mate/Makefile.common"

PKGREVISION=	4
DISTNAME=	mate-icon-theme-faenza-1.20.0
CATEGORIES=	graphics

COMMENT=	Faenza and Faience icon themes for MATE desktop

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/icons

EXTRACT_USING=	gtar

ICON_FILES=	matefaenza matefaenzadark matefaenzagray

post-extract:
	cd ${WRKSRC} && ${FIND} ${ICON_FILES} -type f -exec ${CHMOD} -x \{\} \;

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm ${ICON_FILES} ${DESTDIR}${PREFIX}/share/icons/

.include "../../mk/bsd.pkg.mk"
