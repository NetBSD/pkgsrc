# $NetBSD: Makefile,v 1.6 2024/02/16 20:31:13 nros Exp $

DISTNAME=	qore-process-module-1.0.5
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/module-process/releases/download/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://qore.org/
COMMENT=	Qore module for process handling
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_USE_GNU_INSTALL_DIRS=	no

.include "../../lang/qore/module.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
