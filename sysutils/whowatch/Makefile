# $NetBSD: Makefile,v 1.2 2000/08/11 23:47:48 itojun Exp $
#

DISTNAME=	whowatch-1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${PREFIX}/include"

USE_CURSES=	YES
REPLACE_NCURSES+=whowatch.h configure.in configure

.include "../../mk/bsd.pkg.mk"
