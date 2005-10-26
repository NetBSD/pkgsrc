# $NetBSD: Makefile,v 1.15 2005/10/26 10:08:24 drochner Exp $
#

.include "Makefile.common"

PKGREVISION=	1

PKGCONFIG_OVERRIDE=	libgda.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
