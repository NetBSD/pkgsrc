# $NetBSD: Makefile,v 1.9 2001/09/27 23:17:46 jlam Exp $
#

DISTNAME=	fasthenry-3.0-12Nov96
PKGNAME=	fasthenry-3.0.19961112
WRKSRC=		${WRKDIR}/fasthenry-3.0
CATEGORIES=	cad
MASTER_SITES=	ftp://rle-vlsi.mit.edu/pub/fasthenry/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://kontiki.mit.edu/rle/research/info_research_proj.html
COMMENT=	Three-dimensional inductance extraction program

LICENSE=		no-commercial-use
RESTRICTED=		"No redistribution allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS=		default

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "alpha")
DEPENDS+=	libffm-[0-9]*:../../math/libffm
# optimized libffm (free fast math library)
LIBS=		-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lffm -lm
MAKE_ENV+=	LIBS="${LIBS}"
.else
LIBS=		-lm
.endif

.include "../../mk/bsd.pkg.mk"
