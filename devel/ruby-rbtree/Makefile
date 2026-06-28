# $NetBSD: Makefile,v 1.19 2026/06/28 14:48:01 taca Exp $

DISTNAME=	rbtree-0.4.7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mame/rbtree
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby
LICENSE=	mit

GEM_CLEANBUILD=	Makefile *.o rbtree.${RUBY_DLEXT} mkmf.log .*.time

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
