# $NetBSD: Makefile,v 1.15 2004/03/11 06:52:31 minskim Exp $

DISTNAME=	rosegarden-2.1pl4
PKGNAME=	rosegarden-2.1.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.all-day-breakfast.com/rosegarden/
COMMENT=	Notation editor & MIDI sequencer

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
MAKE_ENV+=	GCC=yes
USE_X11=	YES

post-extract:
	cd ${WRKSRC} && ${MV} Rosegarden Rosegarden.in

.include "../../mk/bsd.pkg.mk"
