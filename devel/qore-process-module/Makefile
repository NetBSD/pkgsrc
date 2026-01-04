# $NetBSD: Makefile,v 1.11 2026/01/04 00:26:42 wiz Exp $

DISTNAME=	qore-process-module-1.0.5
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/module-process/releases/download/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://qore.org/
COMMENT=	Qore module for process handling
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_USE_GNU_INSTALL_DIRS=	no

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../lang/qore/module.mk"

# does not support current boost version, uses included copy - re-check on update
#.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
