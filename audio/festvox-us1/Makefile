# $NetBSD: Makefile,v 1.25 2024/01/30 18:01:40 jperkin Exp $

DISTNAME=	festvox_us1
PKGNAME=	festvox-us1-1.96
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/festival/${PKGVERSION_NOREV}/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://festvox.org/festival/index.html
COMMENT=	MBROLA based American English female voice for festival
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-poslex>=1.4.0:../../audio/festlex-poslex
DEPENDS+=	festlex-cmu>=1.4.0:../../audio/festlex-cmu
DEPENDS+=	mbrola-[0-9]*:../../audio/mbrola
DEPENDS+=	mbrolavox-us1-[0-9]*:../../audio/mbrolavox-us1

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us1_mbrola

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us1 ${DESTDIR}${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us1/us1mrpa ${DESTDIR}${MBROLA}

.include "../../mk/bsd.pkg.mk"
