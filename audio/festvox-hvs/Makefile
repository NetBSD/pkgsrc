# $NetBSD: Makefile,v 1.24 2012/09/11 23:59:33 asau Exp $

DISTNAME=	voice_hvs_di-2.0
PKGNAME=	festvox-hvs-2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.cslu.ogi.edu/tts/download/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	Mexican Spanish female voice for the festival
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi
DEPENDS+=	festogi-spanish>=2.0:../../audio/festogi-spanish

USE_TOOLS+=	pax

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
