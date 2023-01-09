# $NetBSD: Makefile,v 1.18 2023/01/09 07:59:47 taca Exp $

DISTNAME=	inspec-core-5.18.14
PKGREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inspec/inspec
COMMENT=	Core library for Infrastructure and compliance testing
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-chef-telemetry>=1.0<2:../../sysutils/ruby-chef-telemetry
DEPENDS+=	${RUBY_PKGPREFIX}-license-acceptance>=0.2.13:../../misc/ruby-license-acceptance
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0.20:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-method_source>=0.8:../../misc/ruby-method_source
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.2.2:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=3.10<4:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-rspec-its>=1.2<2:../../devel/ruby-rspec-its
DEPENDS+=	${RUBY_PKGPREFIX}-pry>=0.13<1:../../misc/ruby-pry
DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=3.4:../../misc/ruby-hashie
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=3.0<4:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-sslshake>=1.2<2:../../security/ruby-sslshake
DEPENDS+=	${RUBY_PKGPREFIX}-parallel>=1.9<2:../../misc/ruby-parallel
DEPENDS+=	${RUBY_PKGPREFIX}-faraday_middleware>=1.0<2:../../www/ruby-faraday_middleware
DEPENDS+=	${RUBY_PKGPREFIX}-tty-table>=0.10<1:../../devel/ruby-tty-table
DEPENDS+=	${RUBY_PKGPREFIX}-tty-prompt>=0.17<1:../../devel/ruby-tty-prompt
DEPENDS+=	${RUBY_PKGPREFIX}-tomlrb>=1.2:../../devel/ruby-tomlrb
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.4<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-parslet>=1.5:../../devel/ruby-parslet
DEPENDS+=	${RUBY_PKGPREFIX}-semverse>=3.0<4:../../devel/ruby-semverse
DEPENDS+=	${RUBY_PKGPREFIX}-multipart-post>=2.0<3:../../www/ruby-multipart-post
DEPENDS+=	${RUBY_PKGPREFIX}-train-core>=3.0<4:../../net/ruby-train-core

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
