# $NetBSD: Makefile,v 1.11 2000/12/02 02:52:46 wiz Exp $
#

DISTNAME=	gnapster-1.4.1a
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
