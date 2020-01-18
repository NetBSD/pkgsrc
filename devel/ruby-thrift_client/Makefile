# $NetBSD: Makefile,v 1.15 2020/01/18 21:49:16 jperkin Exp $

DISTNAME=	thrift_client-0.7.1
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thrift.apache.org/
COMMENT=	Thrift client wrapper for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-thrift>=0.7.0:../../devel/ruby-thrift

.include "../../devel/libthrift/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
