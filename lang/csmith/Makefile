# $NetBSD: Makefile,v 1.1 2021/09/16 19:19:05 wiz Exp $

DISTNAME=	csmith-2.3.0
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
REPLACE_PERL+=	scripts/test_csmith.pl

.include "../../mk/bsd.pkg.mk"
