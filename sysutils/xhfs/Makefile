# $NetBSD: Makefile,v 1.1.1.1 1999/10/17 04:35:55 fredb Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	xhfs-3.2.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	wrstuden@netbsd.org
HOMEPAGE=	http://www.mars.org/home/rob/proj/hfs/

DEPENDS=	libhfs-3.2.6:../../devel/libhfs
DEPENDS+=	tcl-8.0.5:../../lang/tcl80
DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.0 \
		--with-tk=${LOCALBASE}/lib/tk8.0 --disable-cli
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include/libhfs

.include "../../mk/bsd.pkg.mk"
