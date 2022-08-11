# $NetBSD: Makefile,v 1.4 2022/08/11 05:08:00 gutteridge Exp $

DISTNAME=	xarchiver-0.5.4.17
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=ib/}
GITHUB_PROJECT=	xarchiver
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ib/xarchiver
COMMENT=	GTK+ frontend to various command line archivers
LICENSE=	gnu-gpl-v2

CONFLICTS+=	xfce4-xarchiver-[0-9]*
SUPERSEDES+=	xfce4-xarchiver-[0-9]*
PREV_PKGPATH=	sysutils/xfce4-xarchiver

USE_TOOLS+=	pkg-config perl gmake ggrep
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
