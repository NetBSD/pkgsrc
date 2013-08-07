# $NetBSD: Makefile,v 1.45 2013/08/07 16:48:49 drochner Exp $
#

VERSION=	3.7.2
DISTNAME=	FileZilla_${VERSION}_src
PKGNAME=	filezilla-${VERSION}
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=filezilla/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://filezilla-project.org/
COMMENT=	FTP, FTPS and SFTP client with intuitive GUI
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt msgmerge
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--disable-autoupdatecheck
CONFIGURE_ARGS+=	--with-tinyxml=builtin
# avoid xdg-utils dependency
CONFIGURE_ENV+=		ac_cv_path_xdgopen=firefox

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
