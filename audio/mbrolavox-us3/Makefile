# $NetBSD: Makefile,v 1.2 1999/12/25 22:39:04 wiz Exp $

DISTNAME=	us3-990208
PKGNAME=	mbrolavox-${DISTNAME}
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/us3/
EXTRACT_SUFX=	.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/mbrola.html

DEPENDS+=	mbrola-301h:../mbrola
BUILD_DEPENDS=	unzip:../../archivers/unzip

LICENSE=	no-commercial-use

EXTRACT_CMD=	unzip -Loq ${DOWNLOADED_DISTFILE}

NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && ${PAX} -r -w us3 ${MHOME}

.include "../../mk/bsd.pkg.mk"
