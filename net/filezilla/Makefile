# $NetBSD: Makefile,v 1.113 2019/06/12 00:50:05 gutteridge Exp $

VERSION=	3.42.1
DISTNAME=	FileZilla_${VERSION}_src
PKGNAME=	filezilla-${VERSION}
CATEGORIES=	net x11
MASTER_SITES=	https://download.filezilla-project.org/client/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://filezilla-project.org/
COMMENT=	FTP, FTPS, and SFTP client with intuitive GUI
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt msgmerge xgettext
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--disable-autoupdatecheck
# avoid xdg-utils dependency
CONFIGURE_ENV+=		ac_cv_path_xdgopen=firefox

# GCC 4.9 is required to support C++14.
GCC_REQD+=		4.9

.include "options.mk"

# As of 3.41, 64-bit atomic ops are required
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libfilezilla+=	libfilezilla>=0.16
.include "../../net/libfilezilla/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.4.0
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.tinyxml+=	tinyxml>=2.6.2nb1
.include "../../textproc/pugixml/buildlink3.mk"
BUILDLINK_API_DEPENDS.wxGTK30+=	wxGTK30>=3.0.4
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
