# $NetBSD: Makefile,v 1.33 2012/10/02 21:25:20 asau Exp $
#

.include "Makefile.common"

PKGREVISION=		7

.include "options.mk"

PKGCONFIG_OVERRIDE=	libgda-3.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda-3.0
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no --with-oracle=no

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
