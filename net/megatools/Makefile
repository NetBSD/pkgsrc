# $NetBSD: Makefile,v 1.32 2024/05/16 06:15:22 wiz Exp $

DISTNAME=	megatools-1.11.0-git-20200404
PKGNAME=	megatools-1.11.0.20200404
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	https://megatools.megous.com/builds/experimental/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://megatools.megous.com/
COMMENT=	Command line client for Mega.co.nz
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
