# $NetBSD: Makefile,v 1.4 2002/02/11 17:18:12 jmc Exp $
#

DISTNAME=		cheesetracker-0.2.2
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		impulse tracker clone

DEPENDS+=		gtk-->=1.2:../../x11/gtk--

# Compiler bugs
NOT_FOR_PLATFORM=	NetBSD-*-macppc NetBSD-*-powerpc NetBSD-*-prep \
			NetBSD-*-bebox NetBSD-*-amigappc NetBSD-*-sandpoint
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="-O -Dusleep=pth_usleep -Dwrite=__pthread_write"

.include "../../mk/bsd.pkg.mk"
