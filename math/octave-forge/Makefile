# $NetBSD: Makefile,v 1.3 2004/10/03 00:12:57 tv Exp $
#

DISTNAME=	octave-forge-2004.07.07
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=octave/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://octave.sourceforge.net/
COMMENT=	Extensions to Octave

.if exists(/bin/csplit)
MAKE_ENV+=	CSPLIT=/bin/csplit
.else
BUILD_DEPENDS+=	coreutils-*:../../sysutils/coreutils
MAKE_ENV+=	CSPLIT=${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}csplit
.endif

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

ALL_TARGET=	

GCC_REQD=	3.0
USE_LANGUAGES=	c c++ fortran

.include "../../math/octave-current/octave.mk"

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
.include "../../math/octave-current/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
