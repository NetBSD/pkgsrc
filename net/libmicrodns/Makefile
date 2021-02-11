# $NetBSD: Makefile,v 1.1 2021/02/11 14:43:32 ryoon Exp $

DISTNAME=	microdns-0.2.0
PKGNAME=	${DISTNAME:S/microdns/libmicrodns/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=videolabs/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	libmicrodns
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/videolabs/libmicrodns/
COMMENT=	Minimal mDNS resolver (and announcer) cross-platform library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/microdns.pc.in

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
