# $NetBSD: Makefile,v 1.28 2023/01/29 21:17:53 ryoon Exp $
#

DISTNAME=	hfsutils-3.2.6
PKGNAME=	xhfs-3.2.6
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mars.org/home/rob/proj/hfs/
COMMENT=	Tk GUI + Tcl Shell for accessing HFS volumes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ARGS+=	--disable-cli
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libhfs}/include/libhfs
CPPFLAGS+=		-DUSE_INTERP_RESULT

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			MANDEST=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../devel/libhfs/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
