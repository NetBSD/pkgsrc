# $NetBSD: Makefile,v 1.1.1.1 1999/10/11 17:02:52 proff Exp $

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
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && pax -r -w us3 ${MHOME}

.include "../../mk/bsd.pkg.mk"
