# $NetBSD: Makefile,v 1.31.2.1 2012/10/03 12:07:39 spz Exp $
#

DISTNAME=		tme-0.8
PKGREVISION=		12
CATEGORIES=		emulators
MASTER_SITES=		http://csail.mit.edu/~fredette/tme/

MAINTAINER=		skrll@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

HOMEPAGE=		http://csail.mit.edu/~fredette/tme/
COMMENT=		The Machine Emulator

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run pkg-config

CONFIGURE_ARGS+=	--disable-debug

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
