# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:42 jlam Exp $
#

DISTNAME=		cdrdao-1.1.5.src
PKGNAME=		gcdmaster-1.1.5
WRKSRC=			${WRKDIR}/cdrdao-1.1.5
CATEGORIES=		sysutils
MASTER_SITES=		http://prdownloads.sourceforge.net/cdrdao/

MAINTAINER=		David Maxwell <david@maxwell.net>
HOMEPAGE=		http://cdrdao.sourceforge.net/gcdmaster/index.html
COMMENT=		GUI for cdrdao with some editing capability

BUILD_DEPENDS+=		pccts-1.33.22:../../devel/pccts
DEPENDS+=		cdrdao-1.1.5:../../sysutils/cdrdao
DEPENDS+=		gtk---[0-9]*:../../x11/gtk--
DEPENDS+=		gnome---[0-9]*:../../x11/gnome--
DEPENDS+=		libglade-[0-9]*:../../devel/libglade

USE_X11BASE=		yes
GNU_CONFIGURE=		YES
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

.include "../../mk/bsd.pkg.mk"
