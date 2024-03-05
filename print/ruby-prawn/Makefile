# $NetBSD: Makefile,v 1.18 2024/03/05 13:31:14 taca Exp $

DISTNAME=	prawn-2.5.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-core>=0.10.0<0.11:../../print/ruby-pdf-core
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.8<2:../../fonts/ruby-ttfunk

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
