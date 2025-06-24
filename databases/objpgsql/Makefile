# $NetBSD: Makefile,v 1.3 2025/06/24 16:10:26 js Exp $

PKGNAME=	objpgsql-1.0.1
DISTNAME=	${PKGVERSION_NOREV}-release
CATEGORIES=	databases
MASTER_SITES=	https://git.nil.im/ObjFW/ObjPgSQL/archive/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://git.nil.im/ObjFW/ObjPgSQL
COMMENT=	PostgreSQL bindings for ObjFW
LICENSE=	isc

WRKSRC=			${WRKDIR}/objpgsql
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
