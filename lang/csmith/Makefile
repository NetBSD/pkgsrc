# $NetBSD: Makefile,v 1.3 2022/06/28 11:34:10 wiz Exp $

DISTNAME=	csmith-2.3.0
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://embed.cs.utah.edu/csmith/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://embed.cs.utah.edu/csmith/
COMMENT=	Random generator of C programs
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gm4 gmake perl
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

REPLACE_PERL+=	scripts/compiler_test.pl scripts/launchn.pl

.include "../../mk/bsd.pkg.mk"
