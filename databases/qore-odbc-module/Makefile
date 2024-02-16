# $NetBSD: Makefile,v 1.5 2024/02/16 20:31:13 nros Exp $

DISTNAME=	qore-odbc-module-1.2.0
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/module-odbc/releases/download/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://qore.org/
COMMENT=	ODBC driver for Qore
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_USE_GNU_INSTALL_DIRS=	no

.include "../../lang/qore/module.mk"

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
