# $NetBSD: Makefile,v 1.12 2006/02/05 23:08:25 joerg Exp $
#

DISTNAME=	quirc-0.9.84
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://quirc.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://quirc.org/
COMMENT=	Stable and powerful graphical IRC client

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
