# $NetBSD: Makefile,v 1.3 2014/11/03 18:45:42 prlw1 Exp $

DISTNAME=	libkkc-0.3.4
PKGREVISION=	1
CATEGORIES=	converters textproc japanese inputmethod
MASTER_SITES=	https://bitbucket.org/libkkc/libkkc/downloads/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://bitbucket.org/libkkc/libkkc/
COMMENT=	Japanese Kana Kanji conversion library
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-marisa-[0-9]*:../../textproc/py-marisa

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libkkc/kkc-1.0.pc.in

TEST_TARGET=	check

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
