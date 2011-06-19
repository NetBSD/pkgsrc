# $NetBSD: Makefile,v 1.1.1.1 2011/06/19 14:49:40 taca Exp $

DISTNAME=	prawn-0.11.1
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-reader>=0.9.0:../../print/ruby-pdf-reader
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.0.0<1.1:../../fonts/ruby-ttfunk

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
