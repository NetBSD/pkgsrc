# $NetBSD: Makefile,v 1.18 2025/01/27 14:02:57 wiz Exp $

DISTNAME=	wmnet-1.2
PKGNAME=	wminet-1.2
PKGREVISION=	1
CATEGORIES=	net x11
#MASTER_SITES=	ftp://ftp.enteract.com/users/rneswold/

MAINTAINER=	coto@core.de
#HOMEPAGE=	http://users.rcn.com/rneswold/
COMMENT=	Dockable network monitor

NOT_FOR_PLATFORM=	Interix-*-* # no userland protocol stack support
# if.c:124:25: error: 'const struct ifnet' has no member named 'if_ibytes'
NOT_FOR_PLATFORM+=	NetBSD-1[0-9].*-*

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wminet ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmnet.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wminet.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
