# $NetBSD: Makefile,v 1.7 2007/01/07 09:14:13 rillig Exp $

DISTNAME=	wmSMPmon-2.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://goupilfr.org/arch/

MAINTAINER=	joel@carnat.net
HOMEPAGE=	http://goupilfr.org/?soft=wmsmpmon
COMMENT=	Dockable CPU (SMP) monitor

WRKSRC=		${WRKDIR}/wmSMPmon-2.x/wmSMPmon


post-install:
	${INSTALL_MAN} ${WRKSRC}/wmsmpmon.1 ${PREFIX}/${PKGMANDIR}/man1/wmSMPmon.1

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
