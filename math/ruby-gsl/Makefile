# $NetBSD: Makefile,v 1.19 2017/03/20 13:27:02 taca Exp $

DISTNAME=	gsl-2.1.0.2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SciRuby/rb-gsl/
COMMENT=	Ruby interface to GNU Scientific Library
LICENSE=	gnu-gpl-v2 # OR later

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
