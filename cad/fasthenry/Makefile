# $NetBSD: Makefile,v 1.6 2000/11/02 03:49:09 dmcmahill Exp $
#

DISTNAME=	fasthenry-3.0-12Nov96
PKGNAME=	fasthenry-3.0.19961112
WRKSRC=		${WRKDIR}/fasthenry-3.0
CATEGORIES=	cad
MASTER_SITES=	ftp://rle-vlsi.mit.edu/pub/fasthenry/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://kontiki.mit.edu/rle/research/info_research_proj.html

LICENSE=		no-commercial-use
RESTRICTED=		"No redistribution allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS=		default

.include "../../mk/bsd.pkg.mk"
