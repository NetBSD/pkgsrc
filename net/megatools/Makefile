# $NetBSD: Makefile,v 1.3 2016/10/07 18:26:07 adam Exp $

DISTNAME=	megatools-1.9.95
PKGREVISION=	2
CATEGORIES=	filesystems security
MASTER_SITES=	http://megatools.megous.com/builds/

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://megatools.megous.com/
COMMENT=	Command line client for Mega.co.nz
LICENSE=	gnu-gpl-v2

DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	libmega.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
