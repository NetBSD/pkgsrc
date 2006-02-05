# $NetBSD: Makefile,v 1.1.1.1 2006/02/05 01:25:12 rillig Exp $

DISTNAME=	Botan-1.4.11
PKGNAME=	botan-1.4.11
CATEGORIES=	security
MASTER_SITES=	http://files.randombit.net/botan/
EXTRACT_SUFX=	.tbz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://botan.randombit.net/
COMMENT=	Portable, easy to use, and efficient C++ crypto library

USE_LANGUAGES+=	c++
REPLACE_PERL+=	./configure.pl
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	./configure.pl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

MAKE_FLAGS+=	INSTALL_CMD_EXEC=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=	INSTALL_CMD_DATA=${INSTALL_DATA:Q}

.include "../../mk/bsd.pkg.mk"
