# $NetBSD: Makefile,v 1.12 2008/01/05 05:06:52 obache Exp $

DISTNAME=	Botan-1.4.11
PKGNAME=	botan-1.4.11
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/archive/v1.4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library

BROKEN_IN=		pkgsrc-2006Q4

USE_TOOLS+=	perl

USE_LANGUAGES=	c++
REPLACE_PERL+=	./configure.pl
HAS_CONFIGURE=	yes
CONFIG_SHELL=		perl
CONFIGURE_SCRIPT=	./configure.pl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

MAKE_FLAGS+=	INSTALL_CMD_EXEC=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=	INSTALL_CMD_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

CXXFLAGS.DragonFly+=	-D_DRAGONFLY_SOURCE
CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE
BUILDLINK_TRANSFORM+=	rm:-mcpu=i686

.include "../../mk/bsd.pkg.mk"
