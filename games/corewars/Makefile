# $NetBSD: Makefile,v 1.16 2005/05/22 20:08:00 jlam Exp $

DISTNAME=	corewars-0.9.13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	Programs on a virtual machine, fighting each other

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
