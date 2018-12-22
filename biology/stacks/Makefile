# $NetBSD: Makefile,v 1.1 2018/12/22 21:52:06 bacon Exp $

DISTNAME=	stacks-2.2
CATEGORIES=	biology
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://catchenlab.life.illinois.edu/stacks/
COMMENT=	Software pipeline for building loci from short-read sequences
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++14
GCC_REQD+=	4.9
USE_TOOLS+=	bash perl:run
GNU_CONFIGURE=	yes

REPLACE_BASH=	scripts/stacks-integrate-alignments scripts/stacks-gdb
REPLACE_BASH+=	scripts/stacks-dist-extract
REPLACE_PERL=	scripts/*.pl
REPLACE_PYTHON=	scripts/*.py

CFLAGS+=	-fopenmp

.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
