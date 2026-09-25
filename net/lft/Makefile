# $NetBSD: Makefile,v 1.16 2026/09/25 14:26:21 wiz Exp $

DISTNAME=	lft-4.01
CATEGORIES=	net
MASTER_SITES=	https://pwhois.org/get/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pwhois.org/lft/
COMMENT=	Layer four traceroute capable of tracing protocol paths
LICENSE=	lft-license

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
FAKE_NCURSES=		yes

CFLAGS.SunOS+=		-Dalloca=__builtin_alloca

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lft ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/whob ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lft.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/whob.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
