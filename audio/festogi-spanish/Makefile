# $NetBSD: Makefile,v 1.22 2012/09/11 23:59:33 asau Exp $

DISTNAME=	OGIspanish-2.0.1
PKGNAME=	festogi-spanish-2.0.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	# ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	Festival Spanish (Mexican) language support routines (in scheme)
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${RM} -r ${WRKSRC}/lib/ogi_spanish/CVS

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}

.include "../../mk/bsd.pkg.mk"
