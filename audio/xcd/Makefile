# $NetBSD: Makefile,v 1.5 1998/04/22 14:22:40 agc Exp $
# FreeBSD Id: Makefile,v 1.18 1997/10/08 13:10:20 jmz Exp
#

DISTNAME=	xcd-1.6
CATEGORIES=	audio tk80
MASTER_SITES=	ftp://ftp.obs-besancon.fr/pub/outgoing/

MAINTAINER=	packages@netbsd.org

RUN_DEPENDS=    wish8.0:${PORTSDIR}/x11/tk80
DEPENDS+=	tk-8.0p2:../../x11/tk80

WRKSRC=		${WRKDIR}/xcd
MAN1=		cdplayer.1 xcd.1

.include "../../mk/bsd.pkg.mk"
