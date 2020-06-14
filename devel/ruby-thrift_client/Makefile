# $NetBSD: Makefile,v 1.17 2020/06/14 15:46:02 taca Exp $

DISTNAME=	thrift_client-0.11.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thrift.apache.org/
COMMENT=	Thrift client wrapper for Ruby
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-thrift>=0.7.0:../../devel/ruby-thrift

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
