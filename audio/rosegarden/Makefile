# $NetBSD: Makefile,v 1.5 2002/03/19 12:21:06 wiz Exp $

DISTNAME=	rosegarden-2.1pl3
PKGNAME=	rosegarden-2.1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.all-day-breakfast.com/rosegarden/
COMMENT=	notation editor & MIDI sequencer

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKE_ENV+=	GCC=yes
USE_X11BASE=	YES

USE_BUILDLINK_ONLY=	YES

post-extract:
	cd ${WRKSRC} && ${MV} Rosegarden Rosegarden.in

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
