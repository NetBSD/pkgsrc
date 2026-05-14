# $NetBSD: Makefile,v 1.44 2026/05/14 16:41:48 ryoon Exp $

DISTNAME=	megatools-1.11.4.20250411
PKGREVISION=	5
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
