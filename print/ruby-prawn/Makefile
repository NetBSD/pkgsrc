# $NetBSD: Makefile,v 1.15 2017/09/04 18:00:59 wiz Exp $

DISTNAME=	prawn-2.2.2
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-core>=0.7.0<0.8:../../print/ruby-pdf-core
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.5<2:../../fonts/ruby-ttfunk

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
