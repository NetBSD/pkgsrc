# $NetBSD: Makefile,v 1.2 2003/05/09 00:23:56 salo Exp $
#

.include "../../misc/celestia/Makefile.common"

COMMENT=	Free real-time 3D space simulator

USE_PKGINSTALL=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-kde

EGDIR=		${PREFIX}/share/examples/celestia

CONF_FILES=	${EGDIR}/celestia.cfg.default ${PKG_SYSCONFDIR}/celestia.cfg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/celestia.cfg ${EGDIR}/celestia.cfg.default

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
