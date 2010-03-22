# $NetBSD: Makefile,v 1.27 2010/03/22 16:08:55 joerg Exp $

DISTNAME=	rosegarden-2.1pl4
PKGNAME=	rosegarden-2.1.4
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rosegardenmusic.com/
COMMENT=	Notation editor & MIDI sequencer

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
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
