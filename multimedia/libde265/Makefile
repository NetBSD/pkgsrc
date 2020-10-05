# $NetBSD: Makefile,v 1.2 2020/10/05 11:30:32 wiz Exp $

DISTNAME=	libde265-1.0.7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_PROJECT=	libde265
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libde265/
COMMENT=	Open h.265 video codec implementation
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libde265.pc.in

CONFIGURE_ARGS+=	--disable-sherlock265

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
