# $NetBSD: Makefile,v 1.11 2014/02/12 23:17:50 tron Exp $

DISTNAME=	thrift_client-0.7.1
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://thrift.apache.org/
COMMENT=	Thrift client wrapper for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-thrift>=0.7.0<0.8:../../devel/ruby-thrift

.include "../../devel/libthrift/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
