# $NetBSD: Makefile,v 1.18 2004/04/26 22:15:28 snj Exp $
#

DISTNAME=		cdrdao-1.1.7.src
PKGNAME=		gcdmaster-1.1.7
PKGREVISION=		4
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdrdao/}

MAINTAINER=		david@maxwell.net
HOMEPAGE=		http://cdrdao.sourceforge.net/gcdmaster/index.html
COMMENT=		GUI for cdrdao with some editing capability

DEPENDS+=		cdrdao-1.1.7:../../sysutils/cdrdao

WRKSRC=			${WRKDIR}/cdrdao-1.1.7
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-pcctsbin=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--with-pcctsinc=${LOCALBASE}/include/pccts
CONFIGURE_ARGS+=	--without-posix-threads
LDFLAGS+=		-L../paranoia

#override ARCH to avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""

post-configure:
	cd ${WRKSRC}/scsilib/RULES ; \
	${TEST} -f netbsd-cc.rul || ${MV} i386-netbsd-cc.rul netbsd-cc.rul; \
	${TEST} -f netbsd-gcc.rul || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul; \
	${LN} -sf netbsd-gcc.rul ${MACHINE}-netbsd-gcc.rul; \
	${LN} -sf netbsd-cc.rul ${MACHINE}-netbsd-cc.rul;

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pccts/buildlink3.mk"
.include "../../x11/gnome--/buildlink3.mk"
.include "../../x11/gtk--/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
