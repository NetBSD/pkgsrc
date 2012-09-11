# $NetBSD: Makefile,v 1.22 2012/09/11 23:59:36 asau Exp $

DISTNAME=	festvox_us2
PKGNAME=	festvox-us2-1.4.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival/
COMMENT=	MBROLA based Americal English male voice for festival
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-poslex>=1.4.0:../../audio/festlex-poslex
DEPENDS+=	festlex-cmu>=1.4.0:../../audio/festlex-cmu
DEPENDS+=	mbrola-301h{,nb[0-9]*}:../../audio/mbrola
DEPENDS+=	mbrolavox-us2-980812{,nb[0-9]*}:../../audio/mbrolavox-us2

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us2_mbrola

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us2 ${DESTDIR}${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us2/us2mrpa ${DESTDIR}${MBROLA}

.include "../../mk/bsd.pkg.mk"
