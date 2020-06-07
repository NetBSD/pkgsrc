# $NetBSD: Makefile,v 1.12 2020/06/07 14:42:47 taca Exp $

DISTNAME=	net-scp-3.0.0
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-scp
COMMENT=	Secure copy for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5<7:../../security/ruby-net-ssh

USE_LANGUAGES=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
