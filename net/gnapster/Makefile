# $NetBSD: Makefile,v 1.15 2001/07/22 16:42:45 rh Exp $

DISTNAME=	gnapster-1.5.0
CATEGORIES=	net
MASTER_SITES=	http://www.faradic.net/~jasta/files/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.faradic.net/~jasta/programs.html
COMMENT=	simple client for the online mp3 community

DEPENDS+=	gnome-core-*:../../x11/gnome-core
BUILD_USES_MSGFMT=	yes

USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
