# $NetBSD: Makefile,v 1.14 2009/03/15 21:27:47 jmcneill Exp $

.include "../../sysutils/gamin/Makefile.common"

PKGREVISION=		1
CONFIGURE_ARGS+=	--enable-server

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/libexec
	${INSTALL_LIB} ${WRKSRC}/server/gam_server \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libgamin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
