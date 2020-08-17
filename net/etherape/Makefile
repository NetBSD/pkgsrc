# $NetBSD: Makefile,v 1.109 2020/08/17 20:19:44 leot Exp $

DISTNAME=	etherape-0.9.18
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://etherape.sourceforge.io/
COMMENT=	Graphical network monitor
LICENSE=	gnu-gpl-v2 # or later

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2

USE_TOOLS+=	gmake pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	etherape

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/goocanvas2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
