# $NetBSD: Makefile,v 1.17 2001/02/16 13:30:42 wiz Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:39 max Exp 
#

DISTNAME=       gsm-1.0.10
WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://kbs.cs.tu-berlin.de/~jutta/toast.html
COMMENT=	Audio converter and library for converting u-law to gsm encoding

USE_LIBTOOL=	# defined

NO_CONFIGURE=	# defined
MAKE_ENV+=	INSTALL_ROOT="${PREFIX}" ROOT="${WRKSRC}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/private.h ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/proto.h   ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/unproto.h ${PREFIX}/include/gsm

.include "../../mk/bsd.pkg.mk"
