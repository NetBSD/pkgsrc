# $NetBSD: Makefile,v 1.3 2003/05/22 09:39:07 salo Exp $
#

.include "../../misc/celestia/Makefile.common"

COMMENT=	Free real-time 3D space simulator

USE_PKGINSTALL=	YES

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
