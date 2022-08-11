# $NetBSD: Makefile,v 1.147 2022/08/11 05:09:09 gutteridge Exp $

VERSION=	3.60.1
DISTNAME=	FileZilla_${VERSION}_src
PKGNAME=	filezilla-${VERSION}
PKGREVISION=	1
CATEGORIES=	net x11
MASTER_SITES=	https://download.filezilla-project.org/client/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://filezilla-project.org/
COMMENT=	FTP, FTPS, and SFTP client with intuitive GUI
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++17
USE_TOOLS+=	gmake pkg-config msgfmt msgmerge xgettext
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--disable-autoupdatecheck
# avoid xdg-utils dependency
CONFIGURE_ENV+=		ac_cv_path_xdgopen=firefox
#CONFIGURE_ENV+=	ac_cv_path_WX_CONFIG_PATH=${PREFIX}/bin/wx-config

# For C++17.
GCC_REQD+=		7

.include "options.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libfilezilla+=	libfilezilla>=0.38
.include "../../net/libfilezilla/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.4.0
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.tinyxml+=	tinyxml>=2.6.2nb1
.include "../../textproc/pugixml/buildlink3.mk"
BUILDLINK_API_DEPENDS.wxGTK30+=	wxGTK30>=3.0.4
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
