# $NetBSD: Makefile,v 1.14 2001/03/27 03:20:10 hubertf Exp $

DISTNAME=	gnapster-1.4.2
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

GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
