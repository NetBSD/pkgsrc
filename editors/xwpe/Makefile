# $NetBSD: Makefile,v 1.14 2015/08/17 17:11:22 wiz Exp $
#

DISTNAME=	xwpe-1.5.29a
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_NCURSES=		yes # tigetstr()

BUILD_TARGET=		# the one from the Makefile

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
