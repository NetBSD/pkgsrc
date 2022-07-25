# $NetBSD: Makefile,v 1.12 2022/07/25 11:12:22 wiz Exp $

DISTNAME=	libconfig-1.7.2
CATEGORIES=	devel
MASTER_SITES=	http://hyperrealm.github.io/libconfig/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hyperrealm.github.io/libconfig/
COMMENT=	Simple library for manipulating structured configuration files
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lib/libconfig++.pc.in
PKGCONFIG_OVERRIDE+=	lib/libconfig.pc.in

# https://github.com/hyperrealm/libconfig/pull/127
CHECK_PORTABILITY_SKIP=	contrib/ls-config/debian/postinst

.include "../../mk/bsd.pkg.mk"
