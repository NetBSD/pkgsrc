# $NetBSD: Makefile,v 1.1.1.1 2001/06/18 12:27:36 rh Exp $
#

DISTNAME=		cheesetracker-0.2.1
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		impulse tracker clone

DEPENDS+=		gtk-->=1.2:../../x11/gtk--
BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="-O -Dusleep=pth_usleep -Dwrite=__pthread_write"

pre-configure:
	cd ${WRKSRC} && autoreconf --force

.include "../../mk/bsd.pkg.mk"
