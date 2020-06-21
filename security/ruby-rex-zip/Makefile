# $NetBSD: Makefile,v 1.2 2020/06/21 14:54:51 taca Exp $

DISTNAME=	rex-zip-0.1.3
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-zip
COMMENT=	Ruby Exploitation library for working with zip files
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
