# $NetBSD: Makefile,v 1.15 2026/11/05 15:04:05 taca Exp $

DISTNAME=	net-scp-4.2.1
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-scp
COMMENT=	Secure copy for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5<9:../../security/ruby-net-ssh

USE_LANGUAGES=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
