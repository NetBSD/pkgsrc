# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:57 joerg Exp $

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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
