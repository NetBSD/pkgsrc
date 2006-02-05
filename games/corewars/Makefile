# $NetBSD: Makefile,v 1.17 2006/02/05 23:09:13 joerg Exp $

DISTNAME=	corewars-0.9.13
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	Programs on a virtual machine, fighting each other

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
