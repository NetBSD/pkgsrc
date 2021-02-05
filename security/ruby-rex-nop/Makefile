# $NetBSD: Makefile,v 1.3 2021/02/05 15:15:44 taca Exp $

DISTNAME=	rex-nop-0.1.2
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-nop
COMMENT=	Rex library for dynamic generation of x86 multi-byte NOPs
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-rex-arch-[0-9]*:../../security/ruby-rex-arch

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
