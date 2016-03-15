# $NetBSD: Makefile,v 1.13 2016/03/15 15:05:36 taca Exp $

DISTNAME=	prawn-2.1.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-core>=0.6.0<0.7:../../print/ruby-pdf-core
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.4.0<1.5:../../fonts/ruby-ttfunk

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
