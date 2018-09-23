# $NetBSD: Makefile,v 1.3 2018/09/23 18:02:07 taca Exp $

DISTNAME=	rex-powershell-0.1.79
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-powershell
COMMENT=	Ruby Exploitation library for generating Powershell scripts
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rex-random_identifier-[0-9]*:../../security/ruby-rex-random_identifier
DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
