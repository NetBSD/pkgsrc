# $NetBSD: Makefile,v 1.17 2003/09/17 19:40:03 grant Exp $
#

DISTNAME=	fasthenry-3.0-12Nov96
PKGNAME=	fasthenry-3.0.19961112
WRKSRC=		${WRKDIR}/fasthenry-3.0
CATEGORIES=	cad
MASTER_SITES=	ftp://rle-vlsi.mit.edu/pub/fasthenry/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://kontiki.mit.edu/rle/research/info_research_proj.html
COMMENT=	Three-dimensional inductance extraction program

LICENSE=		no-commercial-use
RESTRICTED=		"No redistribution allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS=		default

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "alpha")
#
# optimized libffm (free fast math library)
#>
.  include "../../math/libffm/buildlink2.mk"
DEPENDS+=	libffm-[0-9]*:../../math/libffm
LIBS=		-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -lffm -lm
MAKE_ENV+=	LIBS="${LIBS}"
.else
LIBS=		-lm
MAKE_ENV+=	LIBS="${LIBS}"
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
USE_PKGSRC_GCC=		# defined
.endif

.include "../../mk/bsd.pkg.mk"
