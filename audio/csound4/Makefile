# $NetBSD: Makefile,v 1.6 2005/05/23 20:40:47 ben Exp $
#

DISTNAME=		csound-4.23f13gbs.0
PKGNAME=		csound4-4.23.13.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/csound/
COMMENT=		Software synthesizer and sequencer

DIST_SUBDIR=		csound
CONFLICTS+=		csound-bath-4*
CONFLICTS+=		csound-dev-4*
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_MAKEINFO=		yes
USE_X11=		yes
TEXINFO_REQD=		4.2
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-g
INFO_FILES=		csoundgbs.info

NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64	# Severe LP64 problems

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
