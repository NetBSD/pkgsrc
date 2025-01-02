# $NetBSD: Makefile,v 1.7 2025/01/02 05:44:03 taca Exp $

DISTNAME=	rex-mime-0.1.10
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-mime
COMMENT=	Rex Library for creating and parsing MIME messages
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
