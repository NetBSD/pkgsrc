# $NetBSD: Makefile,v 1.27 2017/08/01 16:47:36 wiz Exp $

DISTNAME=	voice_aec_di-2.0
PKGNAME=	festvox-aec-2.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	# ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	American English male voice for the festival speech synthesis system
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi

USE_TOOLS+=	pax

DIST_SUBDIR=	${PKGNAME_NOREV}nb1
WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type d -name CVS -print | ${XARGS} ${RM} -fr

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
