# $NetBSD: Makefile,v 1.13 2026/02/02 15:22:28 taca Exp $

DISTNAME=	pathname2-2.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/djberg96/pathname2
COMMENT=	Alternate implementation of the Pathname library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.8<3:../../devel/ruby-facade
DEPENDS+=	${RUBY_PKGPREFIX}-facade>=1.2<2:../../devel/ruby-facade

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
