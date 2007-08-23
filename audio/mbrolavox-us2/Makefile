# $NetBSD: Makefile,v 1.17 2007/08/23 21:08:20 joerg Exp $

DISTNAME=	us2-980812
PKGNAME=	mbrolavox-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/us2/ \
		http://www.festvox.org/mbrola/dba/us2/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/mbrola/
COMMENT=	American English male voice for MBROLA

DEPENDS+=	mbrola-301h{,nb[0-9]*}:../../audio/mbrola

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && ${PAX} -rw us2 ${MHOME}

.include "../../mk/bsd.pkg.mk"
