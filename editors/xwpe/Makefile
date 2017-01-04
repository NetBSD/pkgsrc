# $NetBSD: Makefile,v 1.16 2017/01/04 11:31:59 roy Exp $
#

DISTNAME=	xwpe-1.5.29a
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
INCOMPAT_CURSES+=	NetBSD-[0-5].*-* #tigetstr
FAKE_NCURSES=		yes

BUILD_TARGET=		# the one from the Makefile

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
