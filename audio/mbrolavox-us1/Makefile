# $NetBSD: Makefile,v 1.8 2001/05/19 03:56:32 jlam Exp $

DISTNAME=	us1-980512
PKGNAME=	mbrolavox-us1-980512
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/us1/
EXTRACT_SUFX=	.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/
COMMENT=	American English female voice for MBROLA

DEPENDS+=	mbrola-301h:../mbrola

LICENSE=	no-commercial-use

NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

ONLY_FOR_PLATFORM=      NetBSD-*-i386

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && ${PAX} -r -w us1 ${MHOME}

.include "../../mk/bsd.pkg.mk"
