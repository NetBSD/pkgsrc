# $NetBSD: Makefile,v 1.8 2023/08/14 05:25:01 wiz Exp $

DISTNAME=	microdns-0.2.0
PKGNAME=	${DISTNAME:S/microdns/libmicrodns/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=videolabs/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	libmicrodns
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/videolabs/libmicrodns/
COMMENT=	Minimal mDNS resolver (and announcer) cross-platform library
LICENSE=	gnu-lgpl-v2.1

# error: 'for' loop initial declarations are only allowed in C99 mode
# strict ISO C mode unsuitable for illumos; strerror_r...
FORCE_C_STD=	gnu99

LDFLAGS.SunOS+=	-lsocket

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	src/microdns.pc.in

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
