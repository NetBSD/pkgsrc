# $NetBSD: Makefile,v 1.5 2020/03/24 18:21:24 taca Exp $

DISTNAME=	serverspec-2.41.5
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://serverspec.org/
COMMENT=	RSpec tests for your servers configured by Puppet and more
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=3.0<4:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-its>=0:../../devel/ruby-rspec-its
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=0:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-specinfra>=2.72<3:../../sysutils/ruby-specinfra

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
