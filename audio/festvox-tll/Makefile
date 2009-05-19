# $NetBSD: Makefile,v 1.23 2009/05/19 08:59:03 wiz Exp $

DISTNAME=	voice_tll_di-2.0
PKGNAME=	festvox-tll-2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.cslu.ogi.edu/tts/download/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	American English female voice for the festival speech synthesis system
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-ogi>=2.0:../../audio/festlex-ogi

USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	user-destdir

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
