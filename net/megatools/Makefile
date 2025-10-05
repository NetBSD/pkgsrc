# $NetBSD: Makefile,v 1.40 2025/10/05 19:26:12 js Exp $

DISTNAME=	megatools-1.11.4.20250411
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://xff.cz/megatools/builds/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://xff.cz/megatools/
COMMENT=	Command line client for Mega.nz
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
