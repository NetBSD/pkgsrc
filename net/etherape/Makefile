# $NetBSD: Makefile,v 1.114 2022/08/11 05:09:09 gutteridge Exp $

DISTNAME=	etherape-0.9.20
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=etherape/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://etherape.sourceforge.io/
COMMENT=	Graphical network monitor
LICENSE=	gnu-gpl-v2 # or later

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2

USE_TOOLS+=	gmake pkg-config itstool
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
