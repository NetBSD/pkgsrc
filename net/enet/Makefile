# $NetBSD: Makefile,v 1.5 2024/05/06 13:21:45 nia Exp $

DISTNAME=	enet-1.3.18
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	Pseudo.Statistic@gmail.com
HOMEPAGE=	http://enet.bespin.org/
COMMENT=	Network communication layer that runs on top of UDP
LICENSE=	mit

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no
CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyaddr_r=no

PKGCONFIG_OVERRIDE+=	libenet.pc.in

.include "../../mk/bsd.pkg.mk"
