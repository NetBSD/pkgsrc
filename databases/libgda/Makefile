# $NetBSD: Makefile,v 1.19 2006/04/02 22:46:55 wiz Exp $
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
