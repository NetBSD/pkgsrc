# $NetBSD: Makefile,v 1.1.1.1 2003/05/08 23:47:03 salo Exp $
#

.include "../../misc/celestia/Makefile.common"

COMMENT=	Free real-time 3D space simulator

USE_PKGINSTALL=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-kde

DOCDIR=		${PREFIX}/share/doc/celestia
EGDIR=		${PREFIX}/share/examples/celestia

CONF_FILES=	${EGDIR}/celestia.cfg.default ${PKG_SYSCONFDIR}/celestia.cfg

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/controls.txt ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/celestia.cfg ${EGDIR}/celestia.cfg.default

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
