# $NetBSD: Makefile,v 1.3 2021/03/09 08:58:23 nia Exp $

DISTNAME=	chef-telemetry-1.0.29
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef-telemetry
COMMENT=	Send user actions to the Chef telemetry system
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby
DEPENDS+=	${RUBY_PKGPREFIX}-chef-config>=0:../../sysutils/ruby-chef-config

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# none

RUBY_VERSIONS_INCOMPATIBLE=	25 # ruby-chef-utils

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
