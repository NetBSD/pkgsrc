# $NetBSD: Makefile,v 1.1.1.1 2004/11/28 17:16:48 ben Exp $
#

DISTNAME=		csound-4.23f12gbs.6
PKGNAME=		csound4-4.23.12.6
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/csound/
COMMENT=		Software synthesizer and sequencer

DIST_SUBDIR=		csound
CONFLICTS+=		csound-bath-4*
CONFLICTS+=		csound-dev-4*
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_MAKEINFO=		yes
USE_BUILDLINK3=		yes
USE_X11=		yes
TEXINFO_REQD=		4.2
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-g
INFO_FILES=		csoundgbs.info

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
