# $NetBSD: Makefile,v 1.5 2001/02/16 15:10:53 wiz Exp $
#

DISTNAME=	koth-0.7.6
CATEGORIES=	games
MASTER_SITES=	http://www-unix.oit.umass.edu/~tetron/koth/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www-unix.oit.umass.edu/~tetron/koth/
COMMENT=	The classic "shoot the other tank" artillery game, networked

DEPENDS+=	libgii-0.6:../../graphics/libgii
DEPENDS+=	libggi-2.0b2.1:../../graphics/libggi

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CC="cc -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
