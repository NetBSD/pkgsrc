# $NetBSD: Makefile,v 1.11 2004/01/24 13:30:55 grant Exp $
#

DISTNAME=	corewars-0.9.11
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	Programs on a virtual machine, fighting each other

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
