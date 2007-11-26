# $NetBSD: Makefile,v 1.2 2007/11/26 00:00:33 wiz Exp $
#

DISTNAME=	libconfig-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.hyperrealm.com/libconfig/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.hyperrealm.com/libconfig/
COMMENT=	Simple library for manipulating structured configuration files

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libconfig++.pc.in
PKGCONFIG_OVERRIDE+=	libconfig.pc.in

.include "../../mk/bsd.pkg.mk"
