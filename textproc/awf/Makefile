# $NetBSD: Makefile,v 1.6 2005/09/28 20:52:27 rillig Exp $
#

DISTNAME=	nroff-clone
PKGNAME=	awf-19900907
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.scn.rain.com/pub/text/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scn.rain.com/pub/text/
COMMENT=	Text formatter (nroff-clone) written in awk

EXTRACT_CMD=	${DECOMPRESS_CMD.shar.Z} ${DOWNLOADED_DISTFILE} | ${SED} -e '1,/^\#!/d' | ${SH}
WRKSRC=		${WRKDIR}

NO_TOOLS=	yes
NO_WRAPPER=	# defined

SUBST_CLASSES+=		awflib
SUBST_MESSAGE.awflib=	"Fixing awf library path and awk pathname."
SUBST_FILES.awflib=	Makefile awf awf.1
SUBST_SED.awflib+=	-e 's|/usr/lib/awf|${PREFIX}/share/awf|'
SUBST_SED.awflib+=	-e 's|@AWK@|${AWK}|g'
SUBST_STAGE.awflib=	pre-configure

.include "../../mk/bsd.pkg.mk"
