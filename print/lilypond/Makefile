# $NetBSD: Makefile,v 1.3 2001/02/17 17:51:47 wiz Exp $
#

DISTNAME=	lilypond-1.3.119
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/development/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.cs.uu.nl/people/hanwen/lilypond/index.html
COMMENT=	GNU Music Typesetter

DEPENDS+=	guile>=1.3.4:../../lang/guile
DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

INFO_FILES=	lilypond.info lilypond-internals.info

CONFIGURE_ARGS+=--disable-kpathsea

.include "../../mk/bsd.pkg.mk"
