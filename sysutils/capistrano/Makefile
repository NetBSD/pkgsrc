# $NetBSD: Makefile,v 1.13 2012/09/16 11:14:11 taca Exp $

DISTNAME=	capistrano-2.13.3
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/capistrano/capistrano
COMMENT=	Tool for parallel execution of commands across multiple machines
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.0.14:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-gateway>=1.1.0:../../security/ruby-net-ssh-gateway
DEPENDS+=	${RUBY_PKGPREFIX}-net-sftp>=2.0.0:../../security/ruby-net-sftp
DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=1.0.0:../../security/ruby-net-scp
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=0:../../devel/ruby-highline

CONFLICTS+=	ruby[1-9][0-9]-capistrano-[0-9]* capistrano-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
