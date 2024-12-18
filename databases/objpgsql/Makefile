# $NetBSD: Makefile,v 1.2 2024/12/18 10:30:56 wiz Exp $

DISTNAME=	objpgsql-1.0
CATEGORIES=	databases
MASTER_SITES=	https://fl.nil.im/objpgsql/tarball/${PKGVERSION_NOREV}-release/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://fl.nil.im/objpgsql
COMMENT=	PostgreSQL bindings for ObjFW
LICENSE=	isc

USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
.endif

.include "../../devel/objfw/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
