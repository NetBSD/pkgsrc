# $NetBSD: Makefile,v 1.10 2002/09/22 21:56:28 wiz Exp $

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=       sane-frontends-${SANE_VERSION}

COMMENT=	Frontends for access to scanners, digitals camera, frame grabbers etc

BUILDLINK_DEPENDS.sane=	sane-backends-${SANE_VERSION}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes

# -O to work around a bug with -O2 and egcs.
CFLAGS=		-O

.include "../../graphics/sane-backends/buildlink2.mk"
.include "../../graphics/gimp-base/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
