# $NetBSD: Makefile,v 1.55 2024/10/20 14:03:50 wiz Exp $

DISTNAME=	rftg-0.9.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=bnordli/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keldon.net/rftg/
COMMENT=	AI opponent(s) for the card game Race for the Galaxy
LICENSE=	gnu-gpl-v2 AND rftg-license

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

LIBS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS+=	libexec share/doc/rftg

CHECK_PORTABILITY_SKIP+=	osx/bundle/launcher.sh

WRKSRC=	${WRKDIR}/${DISTNAME}/src/

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/rftg.sh
	${ECHO} 'cd ${PREFIX}/share/rftg && ${PREFIX}/libexec/rftg' \
		>> ${WRKSRC}/rftg.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/rftg ${DESTDIR}${PREFIX}/libexec/rftg
	${INSTALL_SCRIPT} ${WRKSRC}/rftg.sh ${DESTDIR}${PREFIX}/bin/rftg
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/rftg

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
