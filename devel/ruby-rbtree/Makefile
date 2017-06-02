# $NetBSD: Makefile,v 1.15 2017/06/02 04:16:35 taca Exp $

DISTNAME=	rbtree-0.4.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/rbtree/
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby
LICENSE=	mit

GEM_CLEANBUILD=	Makefile *.o rbtree.${RUBY_DLEXT} mkmf.log .*.time

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
