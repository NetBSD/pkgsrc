# $NetBSD: Makefile,v 1.2 2023/05/30 15:32:46 taca Exp $

DISTNAME=	matrix-0.4.2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/matrix
COMMENT=	Implementation of Matrix and Vector classes
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

# This package is for textproc/ruby-classifier-reborn on Ruby 3.0.
# (Ruby 3.1 and 3.2 have the same version as default gem.)
RUBY_VERSIONS_ACCEPTED=	30

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
