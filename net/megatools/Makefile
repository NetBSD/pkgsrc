# $NetBSD: Makefile,v 1.36 2024/11/14 22:21:12 wiz Exp $

DISTNAME=	megatools-1.11.0-git-20200404
PKGNAME=	megatools-1.11.0.20200404
PKGREVISION=	15
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
