# $NetBSD: Makefile,v 1.1 2021/06/09 15:19:57 nia Exp $

DISTNAME=	OpenCL-Headers-v2021.04.29
PKGNAME=	${DISTNAME:tl:S/-v/-/1}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	OpenCL-Headers
GITHUB_TAG=	${DISTNAME:S/^OpenCL-Headers-//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/OpenCL-Headers
COMMENT=	C language headers for the OpenCL API
LICENSE=	apache-2.0

USE_CMAKE=	yes

.include "../../mk/bsd.pkg.mk"
