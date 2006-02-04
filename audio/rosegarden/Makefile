# $NetBSD: Makefile,v 1.19 2006/02/04 16:23:50 ghen Exp $

DISTNAME=	rosegarden-2.1pl4
PKGNAME=	rosegarden-2.1.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rosegardenmusic.com/
COMMENT=	Notation editor & MIDI sequencer

DEPENDS+=	tcl-[0-9]*:../../lang/tcl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
MAKE_ENV+=	GCC=yes

.include "../../mk/x11.buildlink3.mk"

post-extract:
	cd ${WRKSRC} && ${MV} Rosegarden Rosegarden.in

.include "../../mk/bsd.pkg.mk"
