# $NetBSD: Makefile,v 1.16 2005/04/11 21:44:56 tv Exp $

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

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
MAKE_ENV+=	GCC=yes
USE_X11=	YES

post-extract:
	cd ${WRKSRC} && ${MV} Rosegarden Rosegarden.in

.include "../../mk/bsd.pkg.mk"
