# $NetBSD: Makefile,v 1.22 2017/03/20 15:15:31 taca Exp $

DISTNAME=	capistrano-3.8.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/capistrano/capistrano
COMMENT=	Tool for parallel execution of commands across multiple machines
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.9.0:../../security/ruby-sshkit
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-airbrussh>=1.0.0:../../security/ruby-airbrussh

USE_RAKE=	YES

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
