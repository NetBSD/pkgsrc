# $NetBSD: Makefile,v 1.9 1999/12/28 04:19:59 wiz Exp $

DISTNAME=	festvox_don
PKGNAME=	festvox-don-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.4.0:../festival \
		festlex-poslex-1.4.0:../festlex-poslex \
		festlex-oald-1.4.0:../festlex-oald

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
