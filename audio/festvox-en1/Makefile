# $NetBSD: Makefile,v 1.29 2019/11/23 22:08:12 nia Exp $

DISTNAME=	festvox_en1
PKGNAME=	festvox-en1-1.95
CATEGORIES=	audio
MASTER_SITES=	http://festvox.org/packed/festival/${PKGVERSION_NOREV}/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://festvox.org/festival/index.html
COMMENT=	MBROLA based British English male voice for festival
LICENSE=	no-commercial-use

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-poslex>=1.4.0:../../audio/festlex-poslex
DEPENDS+=	festlex-oald>=1.4.0:../../audio/festlex-oald
DEPENDS+=	mbrola-301h{,nb[0-9]*}:../../audio/mbrola
DEPENDS+=	mbrolavox-en1-980910{,nb[0-9]*}:../../audio/mbrolavox-en1

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/en1_mbrola

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FHOME}
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/en1 ${DESTDIR}${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/en1/en1mrpa ${DESTDIR}${MBROLA}

.include "../../mk/bsd.pkg.mk"
