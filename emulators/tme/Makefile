# $NetBSD: Makefile,v 1.8 2005/05/22 20:07:58 jlam Exp $
#

DISTNAME=		tme-0.2
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://theory.lcs.mit.edu/~fredette/tme/

MAINTAINER=		skrll@NetBSD.org
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
