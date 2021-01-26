# $NetBSD: Makefile,v 1.12 2021/01/26 14:54:21 taca Exp $

DISTNAME=	pathname2-1.8.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/djberg96/pathname2
COMMENT=	Alternate implementation of the Pathname library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-facade>=1.0.4:../../devel/ruby-facade

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
