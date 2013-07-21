# $NetBSD: Makefile,v 1.11 2013/07/21 02:42:09 taca Exp $

DISTNAME=	rbtree-0.4.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rbtree/
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby
LICENSE=	mit

GEM_CLEANBUILD=	Makefile *.o rbtree.${RUBY_DLEXT} mkmf.log .RUBYARCHDIR.time

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
