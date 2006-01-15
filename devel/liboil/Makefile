# $NetBSD: Makefile,v 1.1.1.1 2006/01/15 19:51:56 jmmv Exp $
#

DISTNAME=	liboil-0.3.6
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://liboil.freedesktop.org/wiki/
COMMENT=	Library of simple, CPU-optimized functions

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE+=	liboil-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	liboil.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
