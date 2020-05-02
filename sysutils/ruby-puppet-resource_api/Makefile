# $NetBSD: Makefile,v 1.3 2020/05/02 13:53:47 taca Exp $

DISTNAME=	puppet-resource_api-1.8.13
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/puppet-resource_api
COMMENT=	Simple way to write new native resources for puppet
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hocon>=1.0:../../devel/ruby-hocon

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
