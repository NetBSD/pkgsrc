# $NetBSD: Makefile,v 1.19 2003/12/24 13:02:01 jmmv Exp $
#

DISTNAME=	lilypond-1.4.13
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/stable/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.cs.uu.nl/people/hanwen/lilypond/index.html
COMMENT=	GNU Music Typesetter

BUILD_DEPENDS+=	bison>=1.875nb1:../../devel/bison

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
MAKEFILE=		GNUmakefile

USE_MAKEINFO=	YES
TEXINFO_REQD=	4.0
INFO_FILES=	lilypond.info lilypond-internals.info

CONFIGURE_ARGS+=--disable-optimising
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED= 20 21 # 22 has some regular expression problem

.include "../../lang/guile14/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
