# $NetBSD: Makefile,v 1.24 2012/10/02 23:47:57 asau Exp $

DISTNAME=	us1-980512
PKGNAME=	mbrolavox-us1-980512
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://tcts.fpms.ac.be/synthesis/mbrola/dba/us1/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/mbrola/
COMMENT=	American English female voice for MBROLA
LICENSE=	no-commercial-use

DEPENDS+=	mbrola-301h{,nb[0-9]*}:../../audio/mbrola

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MHOME}
	cd ${WRKSRC} && pax -rw us1 ${DESTDIR}${MHOME}

.include "../../mk/bsd.pkg.mk"
