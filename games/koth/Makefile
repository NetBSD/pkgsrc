# $NetBSD: Makefile,v 1.3 1999/08/05 01:56:57 hubertf Exp $
#

DISTNAME=	koth-0.7.2
CATEGORIES=	games
MASTER_SITES=	http://www-unix.oit.umass.edu/~tetron/koth/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www-unix.oit.umass.edu/~tetron/koth/

DEPENDS+=	libgii-0.6:../../graphics/libgii
DEPENDS+=	libggi-2.0b2.1:../../graphics/libggi

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CC="cc -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
