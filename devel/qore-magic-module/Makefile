# $NetBSD: Makefile,v 1.5 2024/02/16 20:31:13 nros Exp $

DISTNAME=	qore-magic-module-1.0.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/module-magic/releases/download/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://qore.org/
COMMENT=	File type identification module for Qore
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

CMAKE_USE_GNU_INSTALL_DIRS=	no

.include "../../lang/qore/module.mk"

.include "../../devel/cmake/build.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
