# $NetBSD: Makefile,v 1.23 2023/12/19 11:05:05 zafer Exp $

DISTNAME=	us3-990208
PKGNAME=	mbrolavox-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	#
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/numediart/MBROLA-voices
COMMENT=	American English male voice for MBROLA
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
	cd ${WRKSRC} && pax -rw us3 ${DESTDIR}${MHOME}

.include "../../mk/bsd.pkg.mk"
