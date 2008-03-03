# $NetBSD: Makefile,v 1.3 2008/03/03 19:31:31 jlam Exp $
#

DISTNAME=	httpfs_with_static_binaries_${DIST_VER}
PKGNAME=	fuse-httpfs-${DIST_VER}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=httpfs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpfs.sourceforge.net/
COMMENT=	FUSE HTTP filesystem

DIST_VER=	2.06.08.26

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

LIBS+=		-lfuse

INSTALLATION_DIRS=	bin

post-extract:
	${RM} ${WRKSRC}/httpfs

do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${LIBS} \
		${WRKSRC}/httpfs.c -o ${WRKSRC}/httpfs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httpfs ${DESTDIR}${PREFIX}/bin

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
