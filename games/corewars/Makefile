# $NetBSD: Makefile,v 1.14 2005/01/14 09:16:04 adam Exp $

DISTNAME=	corewars-0.9.13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	Programs on a virtual machine, fighting each other

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
