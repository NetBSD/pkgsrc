# $NetBSD: Makefile,v 1.10 2000/10/22 11:05:57 rh Exp $
#

DISTNAME=	gnapster-1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.faradic.net/~jasta/files/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.faradic.net/~jasta/programs.html

DEPENDS+=	gnome-core-*:../../x11/gnome-core

USE_X11BASE=	YES
USE_GMAKE=	YES

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include		# libintl.h
CPPFLAGS+=	-DUSE_IMLIB=1

.include "../../mk/bsd.pkg.mk"
