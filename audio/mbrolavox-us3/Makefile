# $NetBSD: Makefile,v 1.8 2001/07/14 12:37:53 jlam Exp $

DISTNAME=	us3-990208
PKGNAME=	mbrolavox-${DISTNAME}
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/us3/
EXTRACT_SUFX=	.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/mbrola.html
COMMENT=	American English male voice for MBROLA

DEPENDS+=	mbrola-301h:../mbrola

LICENSE=	no-commercial-use

NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

ONLY_FOR_PLATFORM=      NetBSD-*-i386

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && ${PAX} -r -w us3 ${MHOME}

.include "../../mk/bsd.pkg.mk"
