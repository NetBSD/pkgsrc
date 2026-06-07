# $NetBSD: Makefile,v 1.31 2026/06/07 03:58:52 taca Exp $

DISTNAME=	rex-socket-0.1.67
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-socket
COMMENT=	Rex socket abstraction library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-core-[0-9]*:../../security/ruby-rex-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
