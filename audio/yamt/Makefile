# $NetBSD: Makefile,v 1.10 2004/01/22 07:15:01 grant Exp $

DISTNAME=	yamt-0.5
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yamt/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://yamt.sourceforge.net/
COMMENT=	Yet Another MP3 Tool

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
