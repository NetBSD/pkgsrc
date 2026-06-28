# $NetBSD: Makefile,v 1.32 2026/06/28 15:19:56 taca Exp $

DISTNAME=	rex-socket-0.1.69
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-socket
COMMENT=	Rex socket abstraction library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-core-[0-9]*:../../security/ruby-rex-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
