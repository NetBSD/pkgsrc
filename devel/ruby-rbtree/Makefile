# $NetBSD: Makefile,v 1.2 2008/04/04 15:30:01 jlam Exp $

DISTNAME=	rbtree-0.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.co.jp/SiliconValley-PaloAlto/3388/rbtree/README.html
COMMENT=	Sorted associative collection using Red-Black Trees for Ruby

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o mkmf.log

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
