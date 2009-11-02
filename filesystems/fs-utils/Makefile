# $NetBSD: Makefile,v 1.8 2009/11/02 19:54:44 stacktic Exp $
#

DISTNAME=		fs-utils_20091102
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		filesystems
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/~stacktic/fs-utils.html
COMMENT=		Tools to access/modify a file system image through RUMP

ONLY_FOR_PLATFORM=	NetBSD-[5-9]*-* FreeBSD-*-* Linux-*-*

PKG_DESTDIR_SUPPORT=	user-destdir
USE_BSD_MAKEFILE=	yes
WRKSRC=			${WRKDIR}/fs-utils
INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile.inc
SUBST_SED.path=		-e "s|/usr/pkg|${LOCALBASE}|g"
SUBST_SED.path+=	-e "s|^LDADD.*|LDADD+= -ldl -L../../../libnbcompat -lnbcompat|"

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libfsu_utils/fsu_fts.h \
	    ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libfsu_utils/fsu_utils.h \
	    ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libfsu_utils/fts2fsufts.h \
	    ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libfsu_mount/fsu_mount.h \
	    ${DESTDIR}${PREFIX}/include

OSNAME!=		uname -s
.if ${OSNAME} != "NetBSD"
MAKEFLAGS+=			NOGCCERROR=1
USE_FEATURES=			nbcompat
NBCOMPAT_CONFIGURE_ARGS+=	CFLAGS='-D_FILE_OFFSET_BITS=64'

.include "../../misc/rump/buildlink3.mk"
.endif # !NetBSD

.include "../../mk/bsd.pkg.mk"
