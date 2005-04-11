# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:30 tv Exp $

DISTNAME=	wmSMPmon-2.3
CATEGORIES=	sysutils x11
MASTER_SITES=	http://goupilfr.org/arch/

MAINTAINER=	joel@carnat.net
HOMEPAGE=	http://goupilfr.org/?soft=wmsmpmon
COMMENT=	Dockable CPU (SMP) monitor

WRKSRC=		${WRKDIR}/wmSMPmon-2.x/wmSMPmon

USE_X11=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/wmsmpmon.1 ${PREFIX}/man/man1/wmSMPmon.1

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
