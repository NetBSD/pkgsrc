# $NetBSD: Makefile,v 1.12 2005/06/01 18:03:23 jlam Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	xhfs-3.2.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@NetBSD.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/
COMMENT=	Tk GUI + Tcl Shell for accessing HFS volumes


GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
		--with-tk=${BUILDLINK_PREFIX.tk}/lib --disable-cli
CPPFLAGS+=	-I${BUILDLINK_PREFIX.libhfs}/include/libhfs

.include "../../devel/libhfs/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
