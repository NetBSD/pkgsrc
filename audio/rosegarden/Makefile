# $NetBSD: Makefile,v 1.34 2022/01/01 07:50:22 dholland Exp $

DISTNAME=	rosegarden-2.1pl4
PKGNAME=	rosegarden-2.1.4
PKGREVISION=	6
CATEGORIES=	audio
#MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
# This package is the (now really old) X11 version of Rosegarden, which
# upstream now barely admits ever existed and had its own version number
# sequence. The following *is* the project home page. Note: if anyone
# gets around to importing a modern Rosegarden, it's probably a good idea
# to keep a copy of this package as rosegarden-x11.
HOMEPAGE=	https://www.rosegardenmusic.com/
COMMENT=	Notation editor & MIDI sequencer

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake makedepend
MAKE_ENV+=	GCC=yes

INSTALLATION_DIRS+=	bin lib/X11/app-defaults

post-extract:
	cd ${WRKSRC} && ${MV} Rosegarden Rosegarden.in

.include "../../x11/libXaw/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
