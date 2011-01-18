# $NetBSD: Makefile,v 1.2 2011/01/18 10:08:43 jmmv Exp $
#

DISTNAME=	telepathy-logger-0.1.6
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-logger/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Logger
COMMENT=	telepathy logger module
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool

PKGCONFIG_OVERRIDE+=	extensions/tpl-extensions.pc.in
PKGCONFIG_OVERRIDE+=	telepathy-logger/telepathy-logger-0.1.pc.in

BUILD_DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

.include "../../devel/glib2/schemas.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
