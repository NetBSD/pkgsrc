# $NetBSD: Makefile,v 1.9.2.1 2013/07/16 17:00:50 tron Exp $

DISTNAME=	rbtree-0.4.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rbtree/
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby
LICENSE=	mit

GEM_CLEANBUILD=	Makefile *.o rbtree.${RUBY_DLEXT} mkmf.log

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
