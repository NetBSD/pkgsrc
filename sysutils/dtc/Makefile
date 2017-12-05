# $NetBSD: Makefile,v 1.7 2017/12/05 09:54:18 adam Exp $

DISTNAME=	dtc-1.4.5
CATEGORIES=	sysutils devel
MASTER_SITES=	https://www.kernel.org/pub/software/utils/dtc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	joe.davis512@gmail.com
HOMEPAGE=	https://devicetree.org/
COMMENT=	Device Tree Compiler (dtc)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run bison flex gmake

REPLACE_BASH+=	dtdiff

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	INSTALL=${INSTALL:Q}
MAKE_FLAGS+=	NO_PYTHON=1

TEST_TARGET=	check

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=libfdt/version.lds

.include "../../mk/bsd.pkg.mk"
