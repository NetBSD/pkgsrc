# $NetBSD: Makefile,v 1.12 2001/01/23 11:52:32 tron Exp $

DISTNAME=	gnapster-1.4.2
CATEGORIES=	net
MASTER_SITES=	http://www.faradic.net/~jasta/files/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.faradic.net/~jasta/programs.html

DEPENDS+=	gnome-core-*:../../x11/gnome-core
BUILD_DEPENDS+=	msgfmt:../../devel/gettext

USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
