# $NetBSD: Makefile,v 1.35 2013/02/16 11:23:08 wiz Exp $

DISTNAME=	octave-forge-2006.03.17
PKGREVISION=	8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=octave/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.octave.org/
COMMENT=	Extensions to Octave

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	none

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		HAVE_MAGICKXX=no

UNLIMIT_RESOURCES=	datasize

BUILD_TARGET=	# empty
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

GCC_REQD+=	3.0
USE_LANGUAGES=	c c++ fortran77

.include "../../math/octave/octave.mk"

PLIST_SUBST+=	OCT_LOCALVERFCNFILEDIR=${OCT_LOCALVERFCNFILEDIR:S/${LOCALBASE}\///}
PLIST_SUBST+=	OCT_LOCALVEROCTFILEDIR=${OCT_LOCALVEROCTFILEDIR:S/${LOCALBASE}\///}
PLIST_SUBST+=	OCT_LOCALVERARCHLIBDIR=${OCT_LOCALVERARCHLIBDIR:S/${LOCALBASE}\///}
PLIST_SUBST+=	OCT_VERSION=${OCT_VERSION:Q}

MESSAGE_SUBST+=	OCT_LOCALVERFCNFILEDIR=${OCT_LOCALVERFCNFILEDIR}
MESSAGE_SUBST+=	OCT_LOCALVEROCTFILEDIR=${OCT_LOCALVEROCTFILEDIR}
MESSAGE_SUBST+=	OCT_LOCALVERARCHLIBDIR=${OCT_LOCALVERARCHLIBDIR}

# the 'fixed' module has problems with recent gcc.  Perhaps
# someone with a c++ clue can fix it.
post-extract:
	${TOUCH} ${WRKSRC}/main/fixed/NOINSTALL

post-patch:
	${MKDIR} ${WRKSRC}/extra/pdb/scripts
	${MV} ${WRKSRC}/extra/pdb/bin/rasmol.sh ${WRKSRC}/extra/pdb/scripts/rasmol.sh

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/octave/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
