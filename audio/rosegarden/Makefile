# $NetBSD: Makefile,v 1.33 2020/01/26 17:30:45 rillig Exp $

DISTNAME=	rosegarden-2.1pl4
PKGNAME=	rosegarden-2.1.4
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
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
