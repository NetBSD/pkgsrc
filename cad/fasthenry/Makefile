# $NetBSD: Makefile,v 1.24 2004/09/22 22:37:27 dmcmahill Exp $
#

DISTNAME=	fasthenry-3.0-12Nov96
PKGNAME=	fasthenry-3.0.19961112
CATEGORIES=	cad
MASTER_SITES=	http://www.rle.mit.edu/cpg/codes/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.rle.mit.edu/cpg/research_codes.htm
COMMENT=	Three-dimensional inductance extraction program

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}/fasthenry-3.0
USE_BUILDLINK3=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS=		default

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "alpha")
#
# optimized libffm (free fast math library)
#>
.  include "../../math/libffm/buildlink3.mk"
DEPENDS+=	libffm-[0-9]*:../../math/libffm
LIBS=		-L${LOCALBASE}/lib ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib -lffm -lm
MAKE_ENV+=	LIBS="${LIBS}"
.else
LIBS=		-lm
MAKE_ENV+=	LIBS="${LIBS}"
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

.include "../../mk/bsd.pkg.mk"
