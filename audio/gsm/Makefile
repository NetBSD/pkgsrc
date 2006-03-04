# $NetBSD: Makefile,v 1.28 2006/03/04 21:28:55 jlam Exp $
#

DISTNAME=       gsm-1.0.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kbs.cs.tu-berlin.de/~jutta/toast.html
COMMENT=	Audio converter and library for converting u-law to gsm encoding

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
USE_LIBTOOL=	yes

NO_CONFIGURE=	yes
MAKE_ENV+=	INSTALL_ROOT=${PREFIX:Q} ROOT=${WRKSRC:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/private.h ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/proto.h   ${PREFIX}/include/gsm
	${INSTALL_DATA} ${WRKSRC}/inc/unproto.h ${PREFIX}/include/gsm

.include "../../mk/bsd.pkg.mk"
