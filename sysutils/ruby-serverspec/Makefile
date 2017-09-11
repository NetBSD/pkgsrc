# $NetBSD: Makefile,v 1.2 2017/09/11 15:57:00 taca Exp $

DISTNAME=	serverspec-2.40.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://serverspec.org/
COMMENT=	RSpec tests for your servers configured by Puppet and more
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=3.0<4:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-its>=0:../../devel/ruby-rspec-its
DEPENDS+=	${RUBY_PKGPREFIX}-multi_json>=0:../../textproc/ruby-multi_json
DEPENDS+=	${RUBY_PKGPREFIX}-specinfra>=2.68<3:../../sysutils/ruby-specinfra

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
