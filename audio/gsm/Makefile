# $NetBSD: Makefile,v 1.37 2020/05/22 09:09:58 nia Exp $

DISTNAME=	gsm-1.0.19
CATEGORIES=	audio
MASTER_SITES=	http://www.quut.com/gsm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.quut.com/gsm/
COMMENT=	Audio converter and library for converting u-law to gsm encoding
LICENSE=	mit

WRKSRC=		${WRKDIR}/gsm-1.0-pl19
USE_LIBTOOL=	yes
NO_CONFIGURE=	yes
MAKE_ENV+=	ROOT=${WRKSRC}
INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	bin include/gsm lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

post-install:
	${INSTALL_DATA} ${WRKSRC}/inc/private.h ${DESTDIR}${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/proto.h   ${DESTDIR}${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/unproto.h ${DESTDIR}${PREFIX}/include/gsm

.include "../../mk/bsd.pkg.mk"
