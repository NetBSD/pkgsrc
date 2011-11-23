# $NetBSD: Makefile,v 1.8 2011/11/23 19:30:08 marino Exp $
#

DISTNAME=	telepathy-logger-0.2.7
PKGREVISION=	3
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
USE_TOOLS+=	pkg-config gmake intltool msgfmt

PKGCONFIG_OVERRIDE+=	extensions/tpl-extensions.pc.in
PKGCONFIG_OVERRIDE+=	telepathy-logger/telepathy-logger-0.1.pc.in

BUILD_DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
