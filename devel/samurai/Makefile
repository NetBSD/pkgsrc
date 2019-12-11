# $NetBSD: Makefile,v 1.1 2019/12/11 23:36:29 ng0 Exp $

DISTNAME=	samurai-0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/samurai/
COMMENT=	Ninja-compatible build tool written in C
LICENSE=	isc AND apache-2.0

BUILD_TARGET=	samu

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
