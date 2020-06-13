# $NetBSD: Makefile,v 1.3 2020/06/13 18:22:12 nia Exp $

DISTNAME=	enet-1.3.15
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

.include "../../mk/bsd.pkg.mk"
