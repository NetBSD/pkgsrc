# $NetBSD: Makefile,v 1.18 2006/02/05 23:08:31 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=		1

PKGCONFIG_OVERRIDE=	libgda-2.0.pc.in

PKG_SYSCONFSUBDIR=	libgda
EGDIR=			${PREFIX}/share/examples/libgda
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config

CONFIGURE_ARGS+=	--with-odbc=no --with-bdb=no

post-install:
	${RMDIR} ${PREFIX}/lib/libgda

.include "../../mk/bsd.pkg.mk"
