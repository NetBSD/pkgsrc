# $NetBSD: Makefile,v 1.8 2025/02/23 14:32:39 taca Exp $

DISTNAME=	rex-mime-0.1.11
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-mime
COMMENT=	Rex Library for creating and parsing MIME messages
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
