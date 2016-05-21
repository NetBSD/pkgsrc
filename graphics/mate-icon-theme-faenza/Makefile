# $NetBSD: Makefile,v 1.1 2016/05/21 18:55:31 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-icon-theme-faenza-${MATE_VERSION}
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
