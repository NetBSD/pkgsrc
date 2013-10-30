# $NetBSD: Makefile,v 1.8 2013/10/30 21:15:49 gls Exp $
#

DISTNAME=	libconfig-1.4.9
CATEGORIES=	devel
MASTER_SITES=	http://www.hyperrealm.com/libconfig/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hyperrealm.com/libconfig/
COMMENT=	Simple library for manipulating structured configuration files
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lib/libconfig++.pc.in
PKGCONFIG_OVERRIDE+=	lib/libconfig.pc.in

.include "../../mk/bsd.pkg.mk"
