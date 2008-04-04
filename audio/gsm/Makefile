# $NetBSD: Makefile,v 1.31 2008/04/04 15:24:20 joerg Exp $
#

DISTNAME=	gsm-1.0.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kbs.cs.tu-berlin.de/~jutta/toast.html
COMMENT=	Audio converter and library for converting u-law to gsm encoding

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/gsm-1.0-pl10
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
