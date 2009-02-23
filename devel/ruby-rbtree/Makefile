# $NetBSD: Makefile,v 1.4 2009/02/23 11:39:42 wiz Exp $

DISTNAME=	rbtree-0.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rbtree/
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o mkmf.log

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
