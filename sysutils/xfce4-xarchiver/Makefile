# $NetBSD: Makefile,v 1.49 2020/11/24 10:43:25 nia Exp $

DISTNAME=	xarchiver-0.5.4.15
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ib/}
GITHUB_PROJECT=	xarchiver
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ib/xarchiver
COMMENT=	Xfce archiver handler
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl gmake
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
