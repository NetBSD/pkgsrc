# $NetBSD: Makefile,v 1.23 2022/01/16 14:29:29 taca Exp $

DISTNAME=	gsl-2.1.0.3
PKGREVISION=	1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SciRuby/rb-gsl/
COMMENT=	Ruby interface to GNU Scientific Library
LICENSE=	gnu-gpl-v2 # OR later

USE_GCC_RUNTIME=	yes

RUBY_VERSIONS_INCOMPATIBLE=	30 31

.include "../../lang/ruby/gem.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
