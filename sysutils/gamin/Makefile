# $NetBSD: Makefile,v 1.28 2026/09/27 11:38:34 tnn Exp $

.include "../../sysutils/gamin/Makefile.common"

PKGREVISION=		12
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
