# $NetBSD: Makefile,v 1.11 2003/10/24 02:01:56 xtraeme Exp $

DISTNAME=	rosegarden-2.1pl4
PKGNAME=	rosegarden-2.1.4
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.all-day-breakfast.com/rosegarden/
COMMENT=	Notation editor & MIDI sequencer

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKE_ENV+=	GCC=yes
USE_X11BASE=	YES

post-extract:
	cd ${WRKSRC} && ${MV} Rosegarden Rosegarden.in

.include "../../lang/tcl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
