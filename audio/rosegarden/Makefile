# $NetBSD: Makefile,v 1.8 2003/06/02 01:21:34 jschauma Exp $

DISTNAME=	rosegarden-2.1pl3
PKGNAME=	rosegarden-2.1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.all-day-breakfast.com/rosegarden/
COMMENT=	notation editor & MIDI sequencer

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKE_ENV+=	GCC=yes
USE_X11BASE=	YES

post-extract:
	cd ${WRKSRC} && ${MV} Rosegarden Rosegarden.in

.include "../../lang/tcl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
