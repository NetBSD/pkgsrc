# $NetBSD: Makefile,v 1.7 2023/11/11 14:18:41 taca Exp $

DISTNAME=	rex-sslscan-0.1.10
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-sslscan
COMMENT=	Rex socket abstraction library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-core-[0-9]*:../../security/ruby-rex-core
DEPENDS+=	${RUBY_PKGPREFIX}-rex-socket-[0-9]*:../../security/ruby-rex-socket
DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
