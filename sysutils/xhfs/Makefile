# $NetBSD: Makefile,v 1.14 2006/02/05 23:10:58 joerg Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	xhfs-3.2.6
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@NetBSD.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/
COMMENT=	Tk GUI + Tcl Shell for accessing HFS volumes


GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--disable-cli
CPPFLAGS+=	-I${BUILDLINK_PREFIX.libhfs}/include/libhfs

.include "../../devel/libhfs/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
