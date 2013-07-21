# $NetBSD: Makefile,v 1.4 2013/07/21 02:50:43 taca Exp $

DISTNAME=	prawn-0.12.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-reader>=0.9.0:../../print/ruby-pdf-reader
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.0.2<1.1:../../fonts/ruby-ttfunk

RUBY_VERSION_SUPPORTED=	200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
