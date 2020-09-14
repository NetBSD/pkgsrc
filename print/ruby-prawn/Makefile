# $NetBSD: Makefile,v 1.16 2020/09/14 14:00:32 taca Exp $

DISTNAME=	prawn-2.3.0
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://prawn.majesticseacreature.com/
COMMENT=	Fast and nimble PDF generator for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-pdf-core>=0.8.1<0.9:../../print/ruby-pdf-core
DEPENDS+=	${RUBY_PKGPREFIX}-ttfunk>=1.6<2:../../fonts/ruby-ttfunk

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
