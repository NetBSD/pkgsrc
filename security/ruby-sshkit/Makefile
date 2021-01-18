# $NetBSD: Makefile,v 1.15 2021/01/18 15:21:21 taca Exp $

DISTNAME=	sshkit-1.21.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/capistrano/sshkit/
COMMENT=	Makes it easy to write structured, testable SSH commands
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.8.0:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=1.1.2:../../security/ruby-net-scp

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
