# $NetBSD: Makefile,v 1.7 2026/07/13 09:55:02 wiz Exp $

DISTNAME=	samurai-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/samurai
COMMENT=	Ninja-compatible build tool written in C
LICENSE=	isc AND apache-2.0

BUILD_TARGET=	samu

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

CFLAGS.SunOS+=	-D__EXTENSIONS__ # getline(3)

.include "../../mk/bsd.pkg.mk"
