# $NetBSD: Makefile,v 1.6 1999/10/27 17:14:04 agc Exp $

DISTNAME=	festvox-ked8-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/
DISTFILES=	festvox_kedlpc8k.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

BROKEN=		16-bit voice conflicts

DEPENDS+=	festival-1.4.0:../festival \
		festlex-poslex-1.4.0:../festlex-poslex \
		festlex-cmu-1.4.0:../festlex-cmu

CONFLICTS=	festvox-ked16-*

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && pax -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
