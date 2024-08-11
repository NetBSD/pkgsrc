# $NetBSD: Makefile,v 1.1 2024/08/11 18:12:44 js Exp $

DISTNAME=	objpgsql-1.0
CATEGORIES=	database
MASTER_SITES=	https://fl.nil.im/objpgsql/tarball/${PKGVERSION_NOREV}-release/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://fl.nil.im/objpgsql
COMMENT=	PostgreSQL bindings for ObjFW
LICENSE=	isc

USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../devel/objfw/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
