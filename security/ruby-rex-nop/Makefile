# $NetBSD: Makefile,v 1.1 2017/10/13 17:59:11 minskim Exp $

DISTNAME=	rex-nop-0.1.1
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-nop
COMMENT=	Rex library for dynamic generation of x86 multi-byte NOPs
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rex-arch-[0-9]*:../../security/ruby-rex-arch

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
