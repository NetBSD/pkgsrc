# $NetBSD: Makefile,v 1.13 2001/09/27 23:17:43 jlam Exp $

DISTNAME=	festvox_rablpc16k
PKGNAME=	festvox-rab16-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	16khz British English male voice for the festival speech synthesis system

DEPENDS+=	festival>=1.4.0:../festival
DEPENDS+=	festlex-poslex>=1.4.0:../festlex-poslex
DEPENDS+=	festlex-oald>=1.4.0:../festlex-oald

CONFLICTS=	festvox-rab8-[0-9]*

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
