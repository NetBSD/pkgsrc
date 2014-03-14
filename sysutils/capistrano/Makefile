# $NetBSD: Makefile,v 1.18 2014/03/14 18:01:03 taca Exp $

DISTNAME=	capistrano-3.1.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/capistrano/capistrano
COMMENT=	Tool for parallel execution of commands across multiple machines
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.3:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0:../../devel/ruby-i18n

USE_RAKE=	YES

CONFLICTS+=	ruby[1-9][0-9]-capistrano-[0-9]* capistrano-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
