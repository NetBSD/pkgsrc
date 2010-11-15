# $NetBSD: Makefile,v 1.27 2010/11/15 22:58:11 abs Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}
PKGREVISION=	9

COMMENT+=	(GTK+ GUI)

DEPENDS+=	bittorrent>=4.4.0:../../net/bittorrent

PYTHON_PATCH_SCRIPTS= bittorrent maketorrent

CONFLICTS+=	bittornado-gui-[0-9]*

ICONS_DIR=		share/pixmaps/BitTorrent-${PKGVERSION:C/nb.*//}/icons
INSTALLATION_DIRS=	bin ${ICONS_DIR} ${ICONS_DIR}/default ${ICONS_DIR}/old

do-build:	# empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bittorrent ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/maketorrent ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/icons/default/* \
	  ${DESTDIR}${PREFIX}/${ICONS_DIR}/default
	${INSTALL_DATA} ${WRKSRC}/images/icons/old/* \
	  ${DESTDIR}${PREFIX}/${ICONS_DIR}/old

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
