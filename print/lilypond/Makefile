# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:32:11 rh Exp $
#

DISTNAME=	lilypond-1.3.86
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/development/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.cs.uu.nl/people/hanwen/lilypond/index.html

DEPENDS+=	guile>=1.3.4:../../lang/guile
DEPENDS+=	python>=1.5.2:../../lang/python
DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=--disable-kpathsea

.include "../../mk/bsd.pkg.mk"
