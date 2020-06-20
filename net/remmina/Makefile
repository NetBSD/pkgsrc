# $NetBSD: Makefile,v 1.54 2020/06/20 00:11:27 ryoon Exp $

DISTNAME=	Remmina-v1.4.6
PKGNAME=	${DISTNAME:S/^R/r/1:S/-v/-/1}
CATEGORIES=	net
MASTER_SITES=	https://gitlab.com/Remmina/Remmina/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.remmina.org/
COMMENT=	Remote desktop client based on GTK+
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++

USE_TOOLS+=	pkg-config msgmerge

REPLACE_SH+=	data/desktop/remmina-file-wrapper.in

CMAKE_ARGS+=	-DWITH_WWW=OFF

LDFLAGS.SunOS+=		-lsocket -lnsl
LDFLAGS.NetBSD+=	-rdynamic

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/freerdp2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../security/kwallet/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../sysutils/spice-gtk/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
