# $NetBSD: Makefile,v 1.24 2004/10/03 00:18:06 tv Exp $
#

DISTNAME=	lilypond-1.4.13
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.uu.nl/pub/GNU/LilyPond/stable/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lilypond.org/web/
COMMENT=	GNU Music Typesetter

BUILD_DEPENDS+=	bison>=1.875nb1:../../devel/bison

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
MAKEFILE=		GNUmakefile

USE_MAKEINFO=	YES
TEXINFO_REQD=	4.0
INFO_FILES=	lilypond.info lilypond-internals.info

CONFIGURE_ARGS+=--disable-optimising
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED= 20 21 # 22 has some regular expression problem

.include "../../lang/guile14/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
