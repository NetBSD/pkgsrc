# $NetBSD: Makefile,v 1.16 2010/04/16 22:32:14 jmmv Exp $

.include "../../sysutils/gamin/Makefile.common"

PKGREVISION=		2
CONFIGURE_ARGS+=	--enable-server

TEST_TARGET=		check

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/libexec
	${INSTALL_LIB} ${WRKSRC}/server/gam_server \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libgamin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
