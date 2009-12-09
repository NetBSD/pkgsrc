# $NetBSD: Makefile,v 1.17 2009/12/09 12:27:27 obache Exp $
#

DISTNAME=		arping-2.08
PKGREVISION=		1
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
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libnet11}/include/libnet11

do-build:
	${CC} -o ${WRKSRC}/arping ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} \
	    ${WRKSRC}/arping-2/arping.c ${LIBS}    

do-install:
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${DESTDIR}${PREFIX}/bin

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
