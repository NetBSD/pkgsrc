# $NetBSD: Makefile,v 1.3 2024/08/25 06:19:16 wiz Exp $

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

PKGCONFIG_OVERRIDE+=	libcue.pc.in

.include "../../mk/bsd.pkg.mk"
