# $NetBSD: Makefile,v 1.12 2012/10/03 16:08:30 asau Exp $
#

DISTNAME=		fs-utils_20091116
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		1
CATEGORIES=		filesystems
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/stacktic/

MAINTAINER=		stacktic@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/~stacktic/fs-utils.html
COMMENT=		Tools to access/modify a file system image through RUMP

ONLY_FOR_PLATFORM=	NetBSD-[5-9]*-* FreeBSD-*-* Linux-*-*

USE_BSD_MAKEFILE=	yes
WRKSRC=			${WRKDIR}/fs-utils
INSTALLATION_DIRS=	bin lib include ${PKGMANDIR}/man1 ${PKGMANDIR}/man3
MAKE_FLAGS+=		MKPROFILE=yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile.gen
SUBST_SED.path=		-e "s|/usr/pkg|${PREFIX}|g"

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
NBCOMPAT_CONFIGURE_ARGS+=	CFLAGS='-D_FILE_OFFSET_BITS=64 -fPIC'
NBCOMPAT_CONFIGURE_ARGS+=	CPPFLAGS='-DPIC'
NBCOMPAT_CONFIGURE_ARGS+=	--enable-bsd-getopt

.include "../../misc/rump/buildlink3.mk"
.endif # !NetBSD

.include "../../mk/bsd.pkg.mk"
