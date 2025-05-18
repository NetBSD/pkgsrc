# $NetBSD: Makefile,v 1.15 2025/05/18 09:29:11 taca Exp $

DISTNAME=	rex-powershell-0.1.102
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-powershell
COMMENT=	Ruby Exploitation library for generating Powershell scripts
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-random_identifier-[0-9]*:../../security/ruby-rex-random_identifier
DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text
DEPENDS+=	${RUBY_PKGPREFIX}-rc4>=0:../../security/ruby-rc4

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
