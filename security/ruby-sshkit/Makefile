# $NetBSD: Makefile,v 1.1 2014/03/14 17:57:47 taca Exp $

DISTNAME=	sshkit-1.3.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/capistrano/sshkit/
COMMENT=	Makes it easy to write structured, testable SSH commands
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=0:../../security/ruby-net-ssh
DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=1.1.2:../../security/ruby-net-scp
DEPENDS+=	${RUBY_PKGPREFIX}-term-ansicolor>=0:../../devel/ruby-term-ansicolor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
