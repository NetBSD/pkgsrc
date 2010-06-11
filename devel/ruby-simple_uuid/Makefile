# $NetBSD: Makefile,v 1.1.1.1 2010/06/11 22:31:08 tonnerre Exp $

DISTNAME=	simple_uuid-0.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://blog.evanweaver.com/files/doc/fauna/simple_uuid/
COMMENT=	Simple, scalable UUID generation for Ruby

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o mkmf.log

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
