# $NetBSD: Makefile,v 1.10 2005/04/01 10:19:58 adam Exp $

DISTNAME=	octave-forge-2004.11.16
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=octave/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://octave.sourceforge.net/
COMMENT=	Extensions to Octave

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes

UNLIMIT_RESOURCES=	datasize

BUILD_TARGET=	# empty
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

GCC_REQD=	3.0
USE_LANGUAGES=	c c++ fortran

.include "../../math/octave/octave.mk"

PLIST_SUBST+=	OCT_LOCALVERFCNFILEDIR=${OCT_LOCALVERFCNFILEDIR:S/${LOCALBASE}\///}
PLIST_SUBST+=	OCT_LOCALVEROCTFILEDIR=${OCT_LOCALVEROCTFILEDIR:S/${LOCALBASE}\///}
PLIST_SUBST+=	OCT_LOCALVERARCHLIBDIR=${OCT_LOCALVERARCHLIBDIR:S/${LOCALBASE}\///}
PLIST_SUBST+=	OCT_VERSION=${OCT_VERSION}

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

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/octave/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
