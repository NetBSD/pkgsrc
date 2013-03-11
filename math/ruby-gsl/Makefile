# $NetBSD: Makefile,v 1.13 2013/03/11 12:28:46 taca Exp $

DISTNAME=	gsl-1.15.3
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rb-gsl.rubyforge.org/
COMMENT=	Ruby interface to GNU Scientific Library
LICENSE=	gnu-gpl-v2 # OR later

DEPENDS+=	${RUBY_PKGPREFIX}-narray>=0.5.9:../../math/ruby-narray

.include "../../lang/ruby/gem.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
