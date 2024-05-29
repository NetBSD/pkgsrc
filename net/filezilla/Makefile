# $NetBSD: Makefile,v 1.171 2024/05/29 16:33:50 adam Exp $

VERSION=	3.67.0
DISTNAME=	FileZilla_${VERSION}_src
PKGNAME=	filezilla-${VERSION}
PKGREVISION=	2
CATEGORIES=	net x11
MASTER_SITES=	https://download.filezilla-project.org/client/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://filezilla-project.org/
COMMENT=	FTP, FTPS, and SFTP client with intuitive GUI
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt msgmerge xgettext
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--disable-autoupdatecheck
# avoid xdg-utils dependency
CONFIGURE_ENV+=		ac_cv_path_xdgopen=firefox
#CONFIGURE_ENV+=	ac_cv_path_WX_CONFIG_PATH=${PREFIX}/bin/wx-config

USE_CXX_FEATURES+=	c++17

.include "options.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libfilezilla+=	libfilezilla>=0.47.0
.include "../../net/libfilezilla/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.4.0
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.tinyxml+=	tinyxml>=2.6.2nb1
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
