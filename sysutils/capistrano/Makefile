# $NetBSD: Makefile,v 1.19 2014/03/26 13:29:09 taca Exp $

DISTNAME=	capistrano-3.1.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/capistrano/capistrano
COMMENT=	Tool for parallel execution of commands across multiple machines
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.3:../../security/ruby-sshkit
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0:../../devel/ruby-i18n

USE_RAKE=	YES

CONFLICTS+=	ruby[1-9][0-9]-capistrano-[0-9]* capistrano-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
