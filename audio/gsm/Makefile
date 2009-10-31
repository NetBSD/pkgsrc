# $NetBSD: Makefile,v 1.33 2009/10/31 01:29:26 wiz Exp $
#

DISTNAME=	gsm-1.0.13
CATEGORIES=	audio
MASTER_SITES=	http://user.cs.tu-berlin.de/~jutta/gsm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kbs.cs.tu-berlin.de/~jutta/toast.html
COMMENT=	Audio converter and library for converting u-law to gsm encoding
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

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
