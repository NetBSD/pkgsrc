# $NetBSD: Makefile,v 1.6 2026/06/20 09:42:30 nia Exp $

DISTNAME=	samurai-1.2
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
