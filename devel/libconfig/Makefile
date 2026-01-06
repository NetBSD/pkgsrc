# $NetBSD: Makefile,v 1.16 2026/01/06 12:19:09 wiz Exp $

DISTNAME=	libconfig-1.8.2
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
