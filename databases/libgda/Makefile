# $NetBSD: Makefile,v 1.31 2012/06/14 07:43:17 sbd Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		6

.include "options.mk"

PKGCONFIG_OVERRIDE=	libgda-3.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda-3.0
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no --with-oracle=no

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
