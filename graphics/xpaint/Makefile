# $NetBSD: Makefile,v 1.47 2005/03/31 11:08:16 adam Exp $

DISTNAME=       xpaint-2.7.6
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xaw95-1.1.4${EXTRACT_SUFX}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://sf-xpaint.sourceforge.net/
COMMENT=	Simple paint program

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_IMAKE=      	yes

BUILD_TARGET=	xaw95
MAKE_ENV+=	XMKMF="${XMKMF}"

SUBST_CLASSES=	    foo
SUBST_STAGE.foo=    pre-configure
SUBST_FILES.foo=    Local.config
SUBST_SED.foo=	    -e "s|\$${LOCALBASE}|${LOCALBASE}|g" \
		    -e "s|\$${X11BASE}|${X11BASE}|g" \
		    -e "s|\$${XPMDIR}|${BUILDLINK_PREFIX.xpm}|g"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
