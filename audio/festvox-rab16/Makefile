# $NetBSD: Makefile,v 1.4 1999/04/14 04:50:25 proff Exp $

DISTNAME=	festvox-rab16-1.3.1
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.3.1/
DISTFILES=	festvox_rablpc16k.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.3.1:../festival
DEPENDS+=	festlex-poslex-1.3.1:../festlex-poslex
DEPENDS+=	festlex-oald-1.3.1:../festlex-oald

CONFLICTS=	festvox-rab8-*

LICENSE=	non-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && pax -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
