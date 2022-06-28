# $NetBSD: Makefile,v 1.16 2022/06/28 10:58:04 nia Exp $

DISTNAME=	memphis-0.2.3
PKGNAME=	libmemphis02-0.2.3
PKGREVISION=	10
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=jiuka/}
GITHUB_PROJECT=	memphis
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jiuka/memphis
COMMENT=	Library for OpenStreetMap
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf autoheader automake gmake pkg-config

CONFIGURE_ARGS+=	--enable-introspection

PKGCONFIG_OVERRIDE+=	memphis.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize --copy; aclocal -I m4; \
	autoheader ; \
	automake -a --foreign -i --add-missing; autoconf

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
