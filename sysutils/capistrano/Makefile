# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:20:41 jlam Exp $

DISTNAME=	capistrano-2.2.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.capify.org/
COMMENT=	Tool for parallel execution of commands across multiple machines

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=1.0.10:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-sftp>=1.1.0:../../security/ruby-net-sftp
DEPENDS+=	${RUBY_PKGPREFIX}-highline>=0:../../devel/ruby-highline

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
