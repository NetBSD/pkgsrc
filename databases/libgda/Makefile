# $NetBSD: Makefile,v 1.12 2005/02/24 19:17:10 drochner Exp $
#

.include "Makefile.common"

PKGCONFIG_OVERRIDE=	libgda.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
