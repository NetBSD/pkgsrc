# $NetBSD: Makefile,v 1.11 2019/11/05 15:28:43 taca Exp $

DISTNAME=	net-scp-2.0.0
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-scp
COMMENT=	Secure copy for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5<6:../../security/ruby-net-ssh

USE_LANGUAGES=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
