# $NetBSD: Makefile,v 1.3 2002/01/11 13:42:14 skrll Exp $
#

DISTNAME=		cheesetracker-0.2.2
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		impulse tracker clone

DEPENDS+=		gtk-->=1.2:../../x11/gtk--

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="-O -Dusleep=pth_usleep -Dwrite=__pthread_write"

.include "../../mk/bsd.pkg.mk"
