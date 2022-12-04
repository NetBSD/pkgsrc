# $NetBSD: Makefile,v 1.13 2022/12/04 16:35:12 taca Exp $

DISTNAME=	net-scp-4.0.0
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-scp
COMMENT=	Secure copy for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5:../../security/ruby-net-ssh

USE_LANGUAGES=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
