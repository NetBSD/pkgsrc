# $NetBSD: Makefile,v 1.10 2002/10/09 23:32:07 wiz Exp $
#

DISTNAME=	lilypond-1.4.13
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/stable/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.cs.uu.nl/people/hanwen/lilypond/index.html
COMMENT=	GNU Music Typesetter

BUILD_DEPENDS+=	bison>=1.32:../../devel/bison

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

TEXINFO_REQD=	4.0
INFO_FILES=	lilypond.info lilypond-internals.info

CONFIGURE_ARGS+=--disable-optimising
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED= 20 21 # 22 has some regular expression problem

.include "../../lang/guile/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
