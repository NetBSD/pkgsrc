# $NetBSD: Makefile,v 1.12 2014/03/13 11:08:51 jperkin Exp $

DISTNAME=	rbtree-0.4.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rbtree/
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby
LICENSE=	mit

GEM_CLEANBUILD=	Makefile *.o rbtree.${RUBY_DLEXT} mkmf.log .RUBYARCHDIR.time

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
