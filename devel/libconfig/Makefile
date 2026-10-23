# $NetBSD: Makefile,v 1.17 2026/10/23 08:13:28 adam Exp $

DISTNAME=	libconfig-1.8.3
CATEGORIES=	devel
MASTER_SITES=	http://hyperrealm.github.io/libconfig/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hyperrealm.github.io/libconfig/
COMMENT=	Simple library for manipulating structured configuration files
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bison
GNU_CONFIGURE=	yes
INFO_FILES=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	lib/libconfig++.pc.in
PKGCONFIG_OVERRIDE+=	lib/libconfig.pc.in

.include "../../mk/bsd.pkg.mk"
