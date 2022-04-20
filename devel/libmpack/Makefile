# $NetBSD: Makefile,v 1.1 2022/04/20 17:56:29 nia Exp $

DISTNAME=	libmpack-1.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libmpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libmpack/libmpack
COMMENT=	Simple implementation of msgpack in C
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	mpack.pc.in

.include "../../mk/bsd.pkg.mk"
