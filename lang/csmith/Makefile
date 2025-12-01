# $NetBSD: Makefile,v 1.4 2025/12/01 09:24:40 wiz Exp $

DISTNAME=	csmith-2.3.0
PKGREVISION=	1
CATEGORIES=	lang
#MASTER_SITES=	${MASTER_SITE_GITHUB:=csmith-project/}
#GITHUB_TAG=	${DISTNAME}
#MASTER_SITES=	https://embed.cs.utah.edu/csmith/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/csmith-project/csmith
COMMENT=	Random generator of C programs
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gm4 gmake perl
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

REPLACE_PERL+=	scripts/compiler_test.pl scripts/launchn.pl

.include "../../mk/bsd.pkg.mk"
