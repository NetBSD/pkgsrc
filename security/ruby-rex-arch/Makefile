# $NetBSD: Makefile,v 1.5 2023/11/11 13:40:08 taca Exp $

DISTNAME=	rex-arch-0.1.15
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-arch
COMMENT=	Rex Library which contains architecture specific information
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
