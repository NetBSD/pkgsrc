# $NetBSD: Makefile,v 1.2 2002/09/21 02:15:57 jlam Exp $

DISTNAME=	yamt-0.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yamt/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://yamt.sourceforge.net/
COMMENT=	Yet Another MP3 Tool

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
BUILD_USES_MSGFMT=	yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
