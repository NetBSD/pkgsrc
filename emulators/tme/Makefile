# $NetBSD: Makefile,v 1.11 2006/10/21 21:53:04 ben Exp $
#

DISTNAME=		tme-0.4
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://theory.lcs.mit.edu/~fredette/tme/

MAINTAINER=		skrll@NetBSD.org
# Please do not assign PR's for this package to skrll.
# Instead, assign them to the package author, fredette.

HOMEPAGE=		http://theory.lcs.mit.edu/~fredette/tme/
COMMENT=		The Machine Emulator

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--disable-debug

.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
