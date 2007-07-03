# $NetBSD: Makefile,v 1.9 2007/07/03 11:23:16 obache Exp $

DISTNAME=	wmSMPmon-2.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://lancre.ribbrock.org/binabit/wmSMPmon/src/

MAINTAINER=	joel@carnat.net
HOMEPAGE=	http://lancre.ribbrock.org/binabit/wmSMPmon/
COMMENT=	Dockable CPU (SMP) monitor

WRKSRC=		${WRKDIR}/wmSMPmon-2.x/wmSMPmon


post-install:
	${INSTALL_MAN} ${WRKSRC}/wmsmpmon.1 ${PREFIX}/${PKGMANDIR}/man1/wmSMPmon.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
