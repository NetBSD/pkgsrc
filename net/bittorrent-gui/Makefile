# $NetBSD: Makefile,v 1.12 2005/07/10 19:11:02 recht Exp $
#

.include "../../net/bittorrent/Makefile.common"

PKGNAME=	${DISTNAME:S/BitTorrent/bittorrent-gui/}

COMMENT+=	(GTK+ GUI)

DEPENDS+=	bittorrent>=4.0.2:../../net/bittorrent

PYTHON_PATCH_SCRIPTS= btdownloadgui.py btmaketorrentgui.py

INSTALLATION_DIRS=	bin

do-build:	# empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/btdownloadgui.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/btmaketorrentgui.py ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${PREFIX}/share/pixmaps/${DISTNAME}/
	${INSTALL_DATA} ${WRKSRC}/images/*.ico ${PREFIX}/share/pixmaps/${DISTNAME}/

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
