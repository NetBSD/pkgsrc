# $NetBSD: Makefile,v 1.20 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=		cdrdao-1.1.9
PKGNAME=		gcdmaster-1.1.9
PKGREVISION=	1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdrdao/}

MAINTAINER=		david@maxwell.net
HOMEPAGE=		http://cdrdao.sourceforge.net/gcdmaster/index.html
COMMENT=		GUI for cdrdao with some editing capability

DEPENDS+=		cdrdao-1.1.9:../../sysutils/cdrdao

WRKSRC=			${WRKDIR}/cdrdao-1.1.9
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
# gtkmm must be 2.0/2.2
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libgnomeuimm20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
