# $NetBSD: Makefile,v 1.16 2006/01/24 07:31:59 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	2

PKGCONFIG_OVERRIDE=	libgda.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
