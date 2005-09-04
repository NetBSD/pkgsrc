# $NetBSD: Makefile,v 1.7 2005/09/04 05:00:36 jlam Exp $

PKGREVISION=	1
COMMENT=	Free real-time 3D space simulator

USE_PKGINSTALL=		yes

EGDIR=		${PREFIX}/share/examples/celestia
CONF_FILES=	${EGDIR}/celestia.cfg.default ${PKG_SYSCONFDIR}/celestia.cfg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/celestia.cfg ${EGDIR}/celestia.cfg.default

.include "../../misc/celestia/Makefile.common"
.include "../../mk/bsd.pkg.mk"
