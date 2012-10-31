# $NetBSD: Makefile,v 1.7 2012/10/31 11:17:11 asau Exp $
#

DISTNAME=	libconfig-1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.hyperrealm.com/libconfig/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
