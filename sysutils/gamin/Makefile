# $NetBSD: Makefile,v 1.17 2010/04/18 18:22:43 jmmv Exp $

.include "../../sysutils/gamin/Makefile.common"

PKGREVISION=		2
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
