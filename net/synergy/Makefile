# $NetBSD: Makefile,v 1.1.1.1 2005/11/21 19:43:06 minskim Exp $
#

DISTNAME=		synergy-1.2.4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synergy2/}

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://synergy2.sourceforge.net/
COMMENT=		Let an user share a mouse and keyboard among computers

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
