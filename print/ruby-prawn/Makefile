# $NetBSD: Makefile,v 1.5 2014/03/14 17:51:20 taca Exp $

DISTNAME=	prawn-0.15.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-core>=0.1.3<0.2:../../print/ruby-pdf-core
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.1.0<1.2:../../fonts/ruby-ttfunk

RUBY_VERSION_SUPPORTED=	200 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
