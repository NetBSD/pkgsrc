# $NetBSD: Makefile,v 1.3 2012/12/21 06:23:19 dholland Exp $

DISTNAME=	prawn-0.12.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-reader>=0.9.0:../../print/ruby-pdf-reader
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.0.2<1.1:../../fonts/ruby-ttfunk

RUBY_VERSION_SUPPORTED=	193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
