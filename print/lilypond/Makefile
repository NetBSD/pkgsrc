# $NetBSD: Makefile,v 1.5 2002/02/18 15:14:38 seb Exp $
#

DISTNAME=	lilypond-1.3.119
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/development/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.cs.uu.nl/people/hanwen/lilypond/index.html
COMMENT=	GNU Music Typesetter

DEPENDS+=	guile>=1.3.4:../../lang/guile
DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

INFO_FILES=	lilypond.info lilypond-internals.info

CONFIGURE_ARGS+=--disable-kpathsea
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED= 20 21 # 22 has some regular expression problem

.include "../../lang/python/application.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
