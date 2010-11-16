# $NetBSD: Makefile,v 1.1.1.1 2010/11/16 20:08:16 drochner Exp $
#

DISTNAME=	gobject-introspection-0.9.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gobject-introspection/0.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GObjectIntrospection
COMMENT=	GObject Introspection
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config flex bison gmake

PKGCONFIG_OVERRIDE+=	gobject-introspection-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-introspection-no-export-1.0.pc.in
PYTHON_VERSIONS_ACCEPTED=	26 25

TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
