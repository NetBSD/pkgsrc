# $NetBSD: Makefile,v 1.4 2021/06/14 15:39:55 taca Exp $

DISTNAME=	puppet-resource_api-1.8.14
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/puppet-resource_api
COMMENT=	Simple way to write new native resources for puppet
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hocon>=1.0:../../devel/ruby-hocon

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
