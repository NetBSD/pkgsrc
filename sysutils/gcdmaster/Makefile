# $NetBSD: Makefile,v 1.20.4.1 2005/06/05 20:39:55 salo Exp $
#

DISTNAME=		cdrdao-1.2.0
PKGNAME=		gcdmaster-1.2.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdrdao/}

MAINTAINER=		david@maxwell.net
HOMEPAGE=		http://cdrdao.sourceforge.net/gcdmaster/index.html
COMMENT=		GUI for cdrdao with some editing capability

DEPENDS+=		cdrdao-1.2.0nb1:../../sysutils/cdrdao

WRKSRC=			${WRKDIR}/cdrdao-1.2.0
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-pcctsbin=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--with-pcctsinc=${LOCALBASE}/include/pccts
CONFIGURE_ARGS+=	--without-posix-threads
CONFIGURE_ARGS+=	--with-xdao
LDFLAGS+=		-L../paranoia

# override ARCH to avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""

.include "../../devel/libgnomeuimm26/buildlink3.mk"
.include "../../devel/libgnomemm26/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/pccts/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/scsilib/RULES ; \
	${TEST} -f netbsd-cc.rul || ${MV} i386-netbsd-cc.rul netbsd-cc.rul; \
	${TEST} -f netbsd-gcc.rul || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul; \
	${LN} -sf netbsd-gcc.rul ${MACHINE}-netbsd-gcc.rul; \
	${LN} -sf netbsd-cc.rul ${MACHINE}-netbsd-cc.rul;

.include "../../mk/bsd.pkg.mk"
