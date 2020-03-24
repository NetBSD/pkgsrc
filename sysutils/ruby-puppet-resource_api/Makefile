# $NetBSD: Makefile,v 1.2 2020/03/24 18:25:55 taca Exp $

DISTNAME=	puppet-resource_api-1.8.12
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/puppet-resource_api
COMMENT=	Simple way to write new native resources for puppet
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hocon>=1.0:../../devel/ruby-hocon

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
