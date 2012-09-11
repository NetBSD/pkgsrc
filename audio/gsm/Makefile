# $NetBSD: Makefile,v 1.34 2012/09/12 00:24:36 asau Exp $
#

DISTNAME=	gsm-1.0.13
CATEGORIES=	audio
MASTER_SITES=	http://user.cs.tu-berlin.de/~jutta/gsm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kbs.cs.tu-berlin.de/~jutta/toast.html
COMMENT=	Audio converter and library for converting u-law to gsm encoding
LICENSE=	mit

WRKSRC=		${WRKDIR}/gsm-1.0-pl13
USE_LIBTOOL=	yes

NO_CONFIGURE=	yes
MAKE_ENV+=	ROOT=${WRKSRC:Q}
INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR:Q}${PREFIX:Q}
INSTALLATION_DIRS=	bin include/gsm lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

post-install:
	${INSTALL_DATA} ${WRKSRC}/inc/private.h ${DESTDIR}${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/proto.h   ${DESTDIR}${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/unproto.h ${DESTDIR}${PREFIX}/include/gsm

.include "../../mk/bsd.pkg.mk"
