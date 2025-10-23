# $NetBSD: Makefile,v 1.26 2025/10/23 20:39:18 wiz Exp $

.include "../../sysutils/gamin/Makefile.common"

PKGREVISION=		10
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
