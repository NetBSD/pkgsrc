# $NetBSD: Makefile,v 1.5 2006/07/21 16:22:36 wiz Exp $

DISTNAME=	Botan-1.4.11
PKGNAME=	botan-1.4.11
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library

USE_TOOLS+=	perl

USE_LANGUAGES+=	c++
REPLACE_PERL+=	./configure.pl
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	./configure.pl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

MAKE_FLAGS+=	INSTALL_CMD_EXEC=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=	INSTALL_CMD_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	LIB_OPT=${CXXFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CXXFLAGS+=	-D_DRAGONFLY_SOURCE
.endif


.include "../../mk/bsd.pkg.mk"
