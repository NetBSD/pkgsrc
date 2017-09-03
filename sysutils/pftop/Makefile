# $NetBSD: Makefile,v 1.17 2017/09/03 08:37:00 wiz Exp $

DISTNAME=	pftop-0.7
PKGREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.eee.metu.edu.tr/~canacar/pftop/
COMMENT=	Utility for real-time display of statistics for PF

NO_CONFIGURE=	yes

MAKE_ENV+=	OSLEVEL=${PF_VERSION:S/.//}
CFLAGS+=	-I${PREFIX}/include
OSVERSION_SPECIFIC=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

post-patch:
	@${ECHO} "#include <pcap.h>" > ${WRKSRC}/pcap-int.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pf.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
