# $NetBSD: Makefile,v 1.18 2012/09/15 10:03:56 obache Exp $
#

DISTNAME=	telepathy-logger-0.2.7
PKGREVISION=	9
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-logger/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Logger
COMMENT=	telepathy logger module
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake gsed intltool msgfmt

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

PKGCONFIG_OVERRIDE+=	extensions/tpl-extensions.pc.in
PKGCONFIG_OVERRIDE+=	telepathy-logger/telepathy-logger-0.1.pc.in

BUILD_DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
