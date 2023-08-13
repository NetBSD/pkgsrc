# $NetBSD: Makefile,v 1.6 2023/08/13 15:01:56 taca Exp $

DISTNAME=	puppet-resource_api-1.9.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/puppet-resource_api
COMMENT=	Simple way to write new native resources for puppet
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hocon>=1.0:../../devel/ruby-hocon

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
