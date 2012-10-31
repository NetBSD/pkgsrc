# $NetBSD: Makefile,v 1.8 2012/10/31 11:19:43 asau Exp $

DISTNAME=	thrift_client-0.7.1
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://thrift.apache.org
COMMENT=	Thrift client wrapper for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-thrift>=0.7.0<0.8:../../devel/ruby-thrift

.include "../../devel/libthrift/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
