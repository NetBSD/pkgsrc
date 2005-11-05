# $NetBSD: Makefile,v 1.14.4.1 2005/11/05 17:20:22 snj Exp $
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
