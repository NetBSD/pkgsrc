# $NetBSD: Makefile,v 1.22 2004/01/20 12:07:42 agc Exp $
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://kbs.cs.tu-berlin.de/~jutta/toast.html
COMMENT=	Audio converter and library for converting u-law to gsm encoding

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
USE_BUILDLINK2=	# defined
USE_LIBTOOL=	# defined

NO_CONFIGURE=	# defined
MAKE_ENV+=	INSTALL_ROOT="${PREFIX}" ROOT="${WRKSRC}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/private.h ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/proto.h   ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/unproto.h ${PREFIX}/include/gsm

.include "../../mk/bsd.pkg.mk"
