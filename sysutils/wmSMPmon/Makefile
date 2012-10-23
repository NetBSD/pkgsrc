# $NetBSD: Makefile,v 1.12 2012/10/23 19:51:34 asau Exp $

DISTNAME=	wmSMPmon-2.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://lancre.ribbrock.org/binabit/wmSMPmon/src/

MAINTAINER=	joel@carnat.net
HOMEPAGE=	http://lancre.ribbrock.org/binabit/wmSMPmon/
COMMENT=	Dockable CPU (SMP) monitor

WRKSRC=		${WRKDIR}/wmSMPmon-2.x/wmSMPmon

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmSMPmon ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmsmpmon.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wmSMPmon.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
