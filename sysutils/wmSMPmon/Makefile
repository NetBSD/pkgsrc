# $NetBSD: Makefile,v 1.6 2006/12/15 20:33:00 joerg Exp $

DISTNAME=	wmSMPmon-2.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://goupilfr.org/arch/

MAINTAINER=	joel@carnat.net
HOMEPAGE=	http://goupilfr.org/?soft=wmsmpmon
COMMENT=	Dockable CPU (SMP) monitor

WRKSRC=		${WRKDIR}/wmSMPmon-2.x/wmSMPmon


post-install:
	${INSTALL_MAN} ${WRKSRC}/wmsmpmon.1 ${PREFIX}/man/man1/wmSMPmon.1

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
