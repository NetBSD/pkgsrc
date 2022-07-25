# $NetBSD: Makefile,v 1.4 2022/07/25 11:12:27 wiz Exp $

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

LDFLAGS.SunOS+=	-lsocket

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	src/microdns.pc.in

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
