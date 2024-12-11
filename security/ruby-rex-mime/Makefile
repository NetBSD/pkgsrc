# $NetBSD: Makefile,v 1.6 2024/12/11 13:44:23 taca Exp $

DISTNAME=	rex-mime-0.1.9
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-mime
COMMENT=	Rex Library for creating and parsing MIME messages
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
