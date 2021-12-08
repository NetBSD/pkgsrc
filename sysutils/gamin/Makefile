# $NetBSD: Makefile,v 1.24 2021/12/08 16:06:28 adam Exp $

.include "../../sysutils/gamin/Makefile.common"

PKGREVISION=		8
CONFIGURE_ARGS+=	--enable-server

TEST_TARGET=		check

.include "options.mk"

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_LIB} ${WRKSRC}/server/gam_server \
		${DESTDIR}${PREFIX}/libexec

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libgamin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
