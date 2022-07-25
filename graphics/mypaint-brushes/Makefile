# $NetBSD: Makefile,v 1.8 2022/07/25 11:12:25 wiz Exp $

DISTNAME=	mypaint-brushes-2.0.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mypaint/}
GITHUB_PROJECT=	mypaint-brushes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mypaint/mypaint-brushes/
COMMENT=	Default MyPaint brushes
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes
AUTOCONF_REQD=	2.62
AUTOMAKE_REQD=	1.13
USE_TOOLS+=	autoconf automake gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	pkgconfig.pc.in

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
