# $NetBSD: Makefile,v 1.34 2020/06/13 15:48:19 taca Exp $

DISTNAME=	capistrano-3.14.1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/capistrano/capistrano
COMMENT=	Tool for parallel execution of commands across multiple machines
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.9.0:../../security/ruby-sshkit
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-airbrussh>=1.0.0:../../security/ruby-airbrussh

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
