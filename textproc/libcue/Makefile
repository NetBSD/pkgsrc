# $NetBSD: Makefile,v 1.4 2025/08/20 11:35:12 wiz Exp $

DISTNAME=	libcue-2.2.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=lipnitsk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lipnitsk/libcue
COMMENT=	CUE Sheet Parser Library
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	flex bison

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	libcue.pc.in

.include "../../mk/bsd.pkg.mk"
