# $NetBSD: Makefile,v 1.1.1.1 2006/05/07 21:41:18 minskim Exp $

DISTNAME=	rgplot-2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rg/gnu/}
CATEGORIES=	graphics
MASTER_SITES=	http://rubyforge.org/frs/download.php/7093/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rgplot.rubyforge.org/
COMMENT=	Ruby interface to a gnuplot process

USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/rgplot

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/gnuplot
.for f in AUTHORS.txt LICENSE.txt howto.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/gnuplot
.endfor

.include "../../mk/bsd.pkg.mk"
