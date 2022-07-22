# $NetBSD: Makefile,v 1.1 2022/07/22 22:08:59 wiz Exp $

DISTNAME=	mypaint-brushes-1.3.1
PKGNAME=	${DISTNAME:S/brushes/brushes1/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mypaint/}
GITHUB_PROJECT=	mypaint-brushes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mypaint/mypaint-brushes/
COMMENT=	Default MyPaint brushes (v1)
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes
AUTOCONF_REQD=	2.62
AUTOMAKE_REQD=	1.13
USE_TOOLS+=	autoconf automake intltool gmake pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	pkgconfig.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

BUILDLINK_DEPMETHOD.glib2=	build
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
