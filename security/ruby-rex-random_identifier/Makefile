# $NetBSD: Makefile,v 1.8 2024/05/26 15:45:32 taca Exp $

DISTNAME=	rex-random_identifier-0.1.12
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-random_identifier
COMMENT=	Ruby Exploitation library for generating random identifiers
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
