# $NetBSD: Makefile,v 1.5 2020/04/17 13:27:57 plunky Exp $

DISTNAME=	libmypaint-1.5.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mypaint/}
GITHUB_PROJECT=	libmypaint
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mypaint.org/
COMMENT=	Library for making brushstrokes
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	gegl/libmypaint-gegl.pc.in
PKGCONFIG_OVERRIDE+=	libmypaint.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
