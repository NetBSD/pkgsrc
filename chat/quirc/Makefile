# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:05 tv Exp $
#

DISTNAME=	quirc-0.9.84
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://quirc.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://quirc.org/
COMMENT=	Stable and powerful graphical IRC client

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
