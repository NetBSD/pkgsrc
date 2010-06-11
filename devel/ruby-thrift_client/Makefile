# $NetBSD: Makefile,v 1.1.1.1 2010/06/11 22:56:52 tonnerre Exp $

DISTNAME=	thrift_client-0.4.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://blog.evanweaver.com/files/doc/fauna/thrift_client/
COMMENT=	Thrift client wrapper for Ruby

GEM_BUILD=	gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-thrift>=0:../../devel/ruby-thrift

.include "../../devel/libthrift/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
