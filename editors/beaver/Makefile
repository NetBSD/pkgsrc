# $NetBSD: Makefile,v 1.68 2026/01/27 08:39:18 wiz Exp $

DISTNAME=	beaver-0.4.1
PKGREVISION=	18
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beaver-editor/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	https://beaver-editor.sourceforge.net/
COMMENT=	Lightweight GTK+2 text editor with syntax highlighting
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl
USE_TOOLS+=	intltool msgfmt msgmerge xgettext

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
