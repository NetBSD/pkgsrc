# $NetBSD: Makefile,v 1.2 2009/12/02 14:46:35 fhajny Exp $

DISTNAME=	capistrano-2.5.10
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.capify.org/
COMMENT=	Tool for parallel execution of commands across multiple machines
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.0.14:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh-gateway>=1.0.0:../../security/ruby-net-ssh-gateway
DEPENDS+=	${RUBY_PKGPREFIX}-net-sftp>=2.0.0:../../security/ruby-net-sftp
DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=1.0.0:../../security/ruby-net-scp
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=0:../../devel/ruby-highline

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
