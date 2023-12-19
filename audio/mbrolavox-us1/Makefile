# $NetBSD: Makefile,v 1.25 2023/12/19 11:02:09 zafer Exp $

DISTNAME=	us1-980512
PKGNAME=	mbrolavox-us1-980512
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	#
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/numediart/MBROLA
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
