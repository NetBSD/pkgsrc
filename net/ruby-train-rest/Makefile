# $NetBSD: Makefile,v 1.1 2022/12/03 13:42:01 taca Exp $

DISTNAME=	train-rest-0.5.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tecracer-chef/train-rest
COMMENT=	Train transport for REST
LICENSE=	apache-2.0


DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=1.5<2:../../www/ruby-aws-sigv4
DEPENDS+=	${RUBY_PKGPREFIX}-train-core>=3.0<4:../../net/ruby-train-core
DEPENDS+=	${RUBY_PKGPREFIX}-rest-client>=2.1<3:../../www/ruby-rest-client

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
