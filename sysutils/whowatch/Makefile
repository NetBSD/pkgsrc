# $NetBSD: Makefile,v 1.3 2001/02/17 17:42:21 wiz Exp $
#

DISTNAME=	whowatch-1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch
COMMENT=	interactive who-like program displaying real-time user information

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${PREFIX}/include"

USE_CURSES=	YES
REPLACE_NCURSES+=whowatch.h configure.in configure

.include "../../mk/bsd.pkg.mk"
