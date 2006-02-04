# $NetBSD: Makefile,v 1.17 2006/02/04 17:02:45 wiz Exp $
#

.include "Makefile.common"

PKGCONFIG_OVERRIDE=	libgda-2.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no

post-install:
	${RMDIR} ${PREFIX}/lib/libgda

.include "../../mk/bsd.pkg.mk"
