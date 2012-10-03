# $NetBSD: Makefile,v 1.33.2.1 2012/10/03 12:09:04 spz Exp $
#

VERSION=	3.5.0
DISTNAME=	FileZilla_${VERSION}_src
PKGNAME=	filezilla-${VERSION}
PKGREVISION=	10
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=filezilla/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://filezilla-project.org/
COMMENT=	FTP, FTPS and SFTP client with intuitive GUI
LICENSE=	gnu-gpl-v2

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt msgmerge
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--disable-autoupdatecheck
CONFIGURE_ARGS+=	--with-tinyxml=builtin

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
