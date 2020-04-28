# $NetBSD: Makefile,v 1.3 2020/04/28 11:46:29 nikita Exp $

DISTNAME=	samurai-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/samurai/
COMMENT=	Ninja-compatible build tool written in C
LICENSE=	isc AND apache-2.0

BUILD_TARGET=	samu

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
