# $NetBSD: Makefile,v 1.5 2004/11/10 16:38:27 adam Exp $

COMMENT=	Free real-time 3D space simulator

USE_PKGINSTALL=		yes

EGDIR=		${PREFIX}/share/examples/celestia
CONF_FILES=	${EGDIR}/celestia.cfg.default ${PKG_SYSCONFDIR}/celestia.cfg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/celestia.cfg ${EGDIR}/celestia.cfg.default

.include "../../misc/celestia/Makefile.common"
