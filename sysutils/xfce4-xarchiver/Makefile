# $NetBSD: Makefile,v 1.46 2020/03/10 22:11:04 wiz Exp $

VERSION=	0.5.4.14
DISTNAME=	xarchiver-${VERSION}
PKGNAME=	xfce4-xarchiver-${VERSION}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ib/}
GITHUB_PROJECT=	xarchiver
GITHUB_TAG=	${VERSION}

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
