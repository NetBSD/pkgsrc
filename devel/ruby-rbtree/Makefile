# $NetBSD: Makefile,v 1.3 2008/08/15 16:06:21 taca Exp $

DISTNAME=	rbtree-0.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rbtree/
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o mkmf.log

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
