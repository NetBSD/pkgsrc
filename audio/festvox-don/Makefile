# $NetBSD: Makefile,v 1.1.1.1 1999/04/04 19:34:08 proff Exp $

DISTNAME=	festvox-don-1.3.1
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.3.1/
DISTFILES=	festvox_don.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.3.1:../festival \
		festlex-poslex-1.3.1:../festlex-poslex \
		festlex-oald-1.3.1:../festlex-oald

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && pax -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
