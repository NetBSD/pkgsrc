# $NetBSD: Makefile,v 1.20 2023/11/11 12:56:09 taca Exp $

DISTNAME=	train-core-3.11.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inspec/train
COMMENT=	Transport interface to talk to a selected set of backends
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.5<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.13.1:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-shellout>=2.0:../../devel/ruby-mixlib-shellout
DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=1.2:../../security/ruby-net-scp
#DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.9:../../security/ruby-net-ssh

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
