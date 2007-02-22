# $NetBSD: Makefile,v 1.12 2007/02/22 17:15:21 rillig Exp $
#

DISTNAME=		arping-2.05
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://www.habets.pp.se/synscan/programs.php?prog=arping
COMMENT=		ARP-level ping utility

LIBS+=			-lnet -lpcap
LIBS.SunOS+=		-lsocket -lnsl
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8
CPPFLAGS+=		-I${LOCALBASE}/include/libnet11

do-build:
	cd ${WRKSRC} && cc ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} -o arping arping-2/arping.c

do-install:
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${PREFIX}/bin

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
