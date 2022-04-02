# $NetBSD: Makefile,v 1.19 2022/04/02 10:50:26 nia Exp $

DISTNAME=	pftop-0.7
PKGREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.eee.metu.edu.tr/~canacar/pftop/
COMMENT=	Utility for real-time display of statistics for PF

NO_CONFIGURE=	yes

MAKE_ENV+=		OSLEVEL=${PF_VERSION:S/.//}
CFLAGS+=		-I${PREFIX}/include
OSVERSION_SPECIFIC=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} > 099974
BROKEN+=	"Depends on removed CIRCLEQ API"
.endif

post-patch:
	@${ECHO} "#include <pcap.h>" > ${WRKSRC}/pcap-int.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pf.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
