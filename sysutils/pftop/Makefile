# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:46 joerg Exp $

DISTNAME=	pftop-0.4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eee.metu.edu.tr/~canacar/pftop/
COMMENT=	Utility for real-time display of statistics for PF

NO_CONFIGURE=	yes

MAKE_ENV+=	OSLEVEL=${PF_VERSION:S/.//}
CFLAGS+=	-I${PREFIX}/include

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
