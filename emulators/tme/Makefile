# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:39 jlam Exp $
#

DISTNAME=		tme-0.2
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://theory.lcs.mit.edu/~fredette/tme/

MAINTAINER=		skrll@NetBSD.org
HOMEPAGE=		http://theory.lcs.mit.edu/~fredette/tme/
COMMENT=		The Machine Emulator

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=	--disable-debug

.include "../../devel/libtool/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
