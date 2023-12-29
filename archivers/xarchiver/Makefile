# $NetBSD: Makefile,v 1.10 2023/12/29 19:38:27 wiz Exp $

DISTNAME=	xarchiver-0.5.4.22
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=ib/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ib/xarchiver
COMMENT=	GTK+ frontend to various command line archivers
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

CONFLICTS+=	xfce4-xarchiver-[0-9]*
SUPERSEDES+=	xfce4-xarchiver-[0-9]*
PREV_PKGPATH=	sysutils/xfce4-xarchiver

USE_TOOLS+=	pkg-config perl gmake ggrep
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
