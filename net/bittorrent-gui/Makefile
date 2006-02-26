# $NetBSD: Makefile,v 1.17 2006/02/26 22:43:33 tron Exp $

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}

COMMENT+=	(GTK+ GUI)

DEPENDS+=	bittorrent>=4.4.0:../../net/bittorrent

PYTHON_PATCH_SCRIPTS= bittorrent maketorrent

CONFLICTS+=	bittornado-gui-[0-9]*

ICONS_DIR=		share/pixmaps/BitTorrent-${PKGVERSION}/icons
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
