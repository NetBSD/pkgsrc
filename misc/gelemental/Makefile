# $NetBSD: Makefile,v 1.49 2023/11/14 14:02:29 wiz Exp $

DISTNAME=	gelemental-2.0.1
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ginggs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ginggs/gelemental
COMMENT=	Periodic table viewer
LICENSE=	mit AND gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt
USE_LANGUAGES=	c c++11

PKGCONFIG_OVERRIDE+=	data/libelemental.pc.in

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
