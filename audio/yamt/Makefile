# $NetBSD: Makefile,v 1.15 2004/10/03 00:13:12 tv Exp $

DISTNAME=	yamt-0.5
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yamt/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://yamt.sourceforge.net/
COMMENT=	Yet Another MP3 Tool

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
