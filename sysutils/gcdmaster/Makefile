# $NetBSD: Makefile,v 1.6 2002/09/12 00:25:29 wiz Exp $
#

DISTNAME=		cdrdao-1.1.5.src
PKGNAME=		gcdmaster-1.1.5
PKGREVISION=		2
WRKSRC=			${WRKDIR}/cdrdao-1.1.5
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cdrdao/}

MAINTAINER=		David Maxwell <david@maxwell.net>
HOMEPAGE=		http://cdrdao.sourceforge.net/gcdmaster/index.html
COMMENT=		GUI for cdrdao with some editing capability

DEPENDS+=		cdrdao-1.1.5:../../sysutils/cdrdao

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
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

.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/pccts/buildlink2.mk"
.include "../../x11/gnome--/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
