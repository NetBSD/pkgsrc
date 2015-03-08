# $NetBSD: Makefile,v 1.15 2015/03/08 15:19:13 taca Exp $

DISTNAME=	rb-gsl-${VERS}
PKGNAME=	${RUBY_PKGPREFIX}-gsl-${VERS}
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/blackwinter/rb-gsl
COMMENT=	Ruby interface to GNU Scientific Library
LICENSE=	gnu-gpl-v2 # OR later

DEPENDS+=	${RUBY_PKGPREFIX}-narray>=0.5.9:../../math/ruby-narray

VERS=		1.16.0.4

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
