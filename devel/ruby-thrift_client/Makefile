# $NetBSD: Makefile,v 1.7 2012/05/06 10:12:20 wiz Exp $

DISTNAME=	thrift_client-0.7.1
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://thrift.apache.org
COMMENT=	Thrift client wrapper for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-thrift>=0.7.0<0.8:../../devel/ruby-thrift

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/libthrift/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
