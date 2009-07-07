# $NetBSD: Makefile,v 1.14 2009/07/07 19:53:00 sno Exp $
#

DISTNAME=		arping-2.08
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://www.habets.pp.se/synscan/programs.php?prog=arping
COMMENT=		ARP-level ping utility
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

LIBS+=			-lnet -lpcap
LIBS.SunOS+=		-lsocket -lnsl
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8
CPPFLAGS+=		-I${LOCALBASE}/include/libnet11

do-build:
	cd ${WRKSRC} && cc ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} -o arping arping-2/arping.c

do-install:
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${DESTDIR}${PREFIX}/bin

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
