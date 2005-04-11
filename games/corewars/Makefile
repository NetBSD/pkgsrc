# $NetBSD: Makefile,v 1.15 2005/04/11 21:45:49 tv Exp $

DISTNAME=	corewars-0.9.13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	Programs on a virtual machine, fighting each other

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
