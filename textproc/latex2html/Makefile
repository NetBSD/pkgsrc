# $NetBSD: Makefile,v 1.1.1.1 2000/11/02 18:19:40 wennmach Exp $

DISTNAME=	latex2html-99.2beta8
CATEGORIES=	textproc converters
MASTER_SITES=   ${MASTER_SITE_TEX_CTAN:=support/latex2html/}

MAINTAINER=	wennmach@netbsd.org
HOMEPAGE=	http://www-dsed.llnl.gov/files/programs/unix/latex2html/manual/

DEPENDS+=       teTeX-bin>=1.0.6:../../print/teTeX-bin
DEPENDS+=	ghostscript>=6.0:../../print/ghostscript
DEPENDS+=	netpbm>=9.7:../../graphics/netpbm

USE_PERL5=	# defined
GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
