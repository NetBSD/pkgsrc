# $NetBSD: Makefile,v 1.11 2003/04/10 01:28:12 grant Exp $

DISTNAME=	us1-980512
PKGNAME=	mbrolavox-us1-980512
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/us1/ \
		http://www.festvox.org/mbrola/dba/us1/
EXTRACT_SUFX=	.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.festvox.org/mbrola/
COMMENT=	American English female voice for MBROLA

DEPENDS+=	mbrola-301h:../mbrola

LICENSE=	no-commercial-use

NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && ${PAX} -rw us1 ${MHOME}

.include "../../mk/bsd.pkg.mk"
