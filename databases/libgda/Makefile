# $NetBSD: Makefile,v 1.13 2005/03/26 11:16:15 recht Exp $
#

.include "Makefile.common"

PKGCONFIG_OVERRIDE=	libgda.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
