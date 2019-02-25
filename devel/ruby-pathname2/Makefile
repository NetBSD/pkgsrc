# $NetBSD: Makefile,v 1.10 2019/02/25 16:41:12 taca Exp $

DISTNAME=	pathname2-1.8.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/djberg96/pathname2
COMMENT=	Alternate implementation of the Pathname library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-facade>=1.0.4:../../devel/ruby-facade

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
