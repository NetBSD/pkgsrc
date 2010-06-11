# $NetBSD: Makefile,v 1.1.1.1 2010/06/11 22:50:40 tonnerre Exp $

DISTNAME=	thrift-0.2.0.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://blog.evanweaver.com/files/doc/fauna/thrift/
COMMENT=	Ruby libraries for Thrift (a language-agnostic RPC system)

GEM_BUILD=	gemspec

.include "../../devel/libthrift/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
