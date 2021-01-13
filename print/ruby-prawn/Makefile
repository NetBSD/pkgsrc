# $NetBSD: Makefile,v 1.17 2021/01/13 14:59:46 taca Exp $

DISTNAME=	prawn-2.4.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-core>=0.9.0<0.10:../../print/ruby-pdf-core
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.7<2:../../fonts/ruby-ttfunk

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
