# $NetBSD: Makefile,v 1.23 2007/08/04 11:13:37 obache Exp $
#

.include "Makefile.common"

.include "options.mk"

PKGCONFIG_OVERRIDE=	libgda-3.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda-3.0
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
