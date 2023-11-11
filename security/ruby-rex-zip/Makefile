# $NetBSD: Makefile,v 1.4 2023/11/11 14:31:22 taca Exp $

DISTNAME=	rex-zip-0.1.5
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-zip
COMMENT=	Ruby Exploitation library for working with zip files
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
