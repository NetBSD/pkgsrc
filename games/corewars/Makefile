# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:43 tv Exp $
#

DISTNAME=	corewars-0.9.11
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	Programs on a virtual machine, fighting each other

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
