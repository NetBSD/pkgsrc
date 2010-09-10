# $NetBSD: Makefile,v 1.2 2010/09/10 06:32:52 taca Exp $

DISTNAME=	thrift_client-0.4.6
CATEGORIES=	devel

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://blog.evanweaver.com/files/doc/fauna/thrift_client/
COMMENT=	Thrift client wrapper for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-thrift>=0:../../devel/ruby-thrift

.include "../../devel/libthrift/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
