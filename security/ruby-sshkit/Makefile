# $NetBSD: Makefile,v 1.16 2021/02/03 15:07:00 taca Exp $

DISTNAME=	sshkit-1.21.2
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
