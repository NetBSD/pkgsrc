# $NetBSD: Makefile,v 1.2 1999/07/06 08:02:02 jlam Exp $
#

DISTNAME=	tnt1.9-pre3
PKGNAME=	tnt-1.9p3
CATEGORIES=	ham
MASTER_SITES=	ftp://excelsior.kullen.rwth-aachen.de/pub/packet_radio/tnt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://excelsior.kullen.rwth-aachen.de

DEPENDS+=	dialog-0.6z:../../misc/dialog
DEPENDS+=	ncurses-4.2:../../devel/ncurses

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include	# for ncurses' termcap.h
LDFLAGS+=	-L${LOCALBASE}/lib	# for -lncurses
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
