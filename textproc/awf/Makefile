# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:50 jmmv Exp $
#

DISTNAME=	nroff-clone
PKGNAME=	awf-19900907
CATEGORIES=	textproc
MASTER_SITES=	http://www.scn.rain.com/pub/text/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scn.rain.com/pub/text/
COMMENT=	Text formatter (nroff-clone) written in awk

BUILD_DEPENDS=	gsharutils>=4.2.1:../../archivers/gsharutils

EXTRACT_CMD=	zcat ${DOWNLOADED_DISTFILE} | gunshar
WRKSRC=		${WRKDIR}

SUBST_CLASSES+=		awflib
SUBST_MESSAGE.awflib=	"Fixing awf library path."
SUBST_FILES.awflib=	Makefile awf awf.1
SUBST_SED.awflib=	-e 's|/usr/lib/awf|${PREFIX}/share/awf|'
SUBST_STAGE.awflib=	post-patch

.include "../../mk/bsd.pkg.mk"
