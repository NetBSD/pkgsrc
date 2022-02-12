# $NetBSD: Makefile,v 1.17 2022/02/12 13:14:07 taca Exp $

DISTNAME=	rbtree-0.4.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/rbtree/
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby
LICENSE=	mit

GEM_CLEANBUILD=	Makefile *.o rbtree.${RUBY_DLEXT} mkmf.log .*.time

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
