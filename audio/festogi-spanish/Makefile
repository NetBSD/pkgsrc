# $NetBSD: Makefile,v 1.17 2006/12/28 11:47:51 wiz Exp $

DISTNAME=	OGIspanish-2.0.1
PKGNAME=	festogi-spanish-2.0.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	Festival Spanish (Mexican) language support routines (in scheme)

DEPENDS+=	festival>=1.4.0:../../audio/festival

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${RM} -r ${WRKSRC}/lib/ogi_spanish/CVS

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -rw * ${FHOME}

.include "../../mk/bsd.pkg.mk"
