# $NetBSD: Makefile,v 1.26 2019/11/23 12:22:35 nia Exp $

DISTNAME=	festvox_kallpc16k
PKGNAME=	festvox-kal16-2.5
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/festival/${PKGVERSION_NOREV}/voices/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://festvox.org/festival/index.html
COMMENT=	16khz American English male voice for festival

DEPENDS+=	festival>=2.5.0:../../audio/festival
DEPENDS+=	festlex-poslex>=2.5:../../audio/festlex-poslex
DEPENDS+=	festlex-cmu>=2.5:../../audio/festlex-cmu

USE_TOOLS+=	pax

CONFLICTS=	festvox-kal8-[0-9]*

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
