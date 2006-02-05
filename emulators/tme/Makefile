# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:04 joerg Exp $
#

DISTNAME=		tme-0.4
PKGREVISION=		1
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
