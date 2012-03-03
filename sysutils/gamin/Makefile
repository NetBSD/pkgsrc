# $NetBSD: Makefile,v 1.20 2012/03/03 00:13:55 wiz Exp $

.include "../../sysutils/gamin/Makefile.common"

PKGREVISION=		5
CONFIGURE_ARGS+=	--enable-server

TEST_TARGET=		check

.include "options.mk"

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/libexec
	${INSTALL_LIB} ${WRKSRC}/server/gam_server \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libgamin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
