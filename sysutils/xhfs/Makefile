# $NetBSD: Makefile,v 1.6 2003/07/17 22:53:58 grant Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	xhfs-3.2.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@NetBSD.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/
COMMENT=	Tk GUI + Tcl Shell for accessing HFS volumes

DEPENDS=	libhfs-3.2.6:../../devel/libhfs
DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib \
		--with-tk=${LOCALBASE}/lib --disable-cli
CPPFLAGS+=	-I${LOCALBASE}/include/libhfs

.include "../../mk/bsd.pkg.mk"
