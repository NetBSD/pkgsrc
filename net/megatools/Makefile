# $NetBSD: Makefile,v 1.20 2020/04/07 14:14:55 maya Exp $

DISTNAME=	megatools-1.11.0-git-20200404
PKGNAME=	megatools-1.11.0.20200404
CATEGORIES=	net
MASTER_SITES=	https://megatools.megous.com/builds/experimental/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://megatools.megous.com/
COMMENT=	Command line client for Mega.co.nz
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
