# $NetBSD: Makefile,v 1.22 2007/01/21 19:14:20 wiz Exp $
#

.include "Makefile.common"

PKGCONFIG_OVERRIDE=	libgda-3.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no

.include "../../mk/bsd.pkg.mk"
