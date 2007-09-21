# $NetBSD: Makefile,v 1.20 2007/09/21 13:04:10 wiz Exp $

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}
PKGREVISION=	3

COMMENT+=	(GTK+ GUI)

DEPENDS+=	bittorrent>=4.4.0:../../net/bittorrent

PYTHON_PATCH_SCRIPTS= bittorrent maketorrent

CONFLICTS+=	bittornado-gui-[0-9]*

ICONS_DIR=		share/pixmaps/BitTorrent-${PKGVERSION:C/nb.*//}/icons
INSTALLATION_DIRS=	bin ${ICONS_DIR} ${ICONS_DIR}/default ${ICONS_DIR}/old

do-build:	# empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bittorrent ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/maketorrent ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/icons/default/* \
	  ${PREFIX}/${ICONS_DIR}/default
	${INSTALL_DATA} ${WRKSRC}/images/icons/old/* \
	  ${PREFIX}/${ICONS_DIR}/old

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
