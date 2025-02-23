# $NetBSD: Makefile,v 1.5 2025/02/23 14:33:49 taca Exp $

DISTNAME=	rex-nop-0.1.4
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-nop
COMMENT=	Rex library for dynamic generation of x86 multi-byte NOPs
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-arch-[0-9]*:../../security/ruby-rex-arch

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
