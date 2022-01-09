# $NetBSD: Makefile,v 1.13 2022/01/09 14:41:05 pho Exp $

DISTNAME=	loggedfs-0.4
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=loggedfs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rflament.github.io/loggedfs/
COMMENT=	FUSE file system which logs all operations
LICENSE=	gnu-gpl-v2

# loggedfs performs a weird hack that obtains a reference to the
# directory it is going to be mounted on, and then tries to inspect
# the directory in filesystem callbacks. On Linux this can somehow
# avoid deadlocks (possibly due to the way how Linux vfs is
# implemented?), but on NetBSD it can't. As a result loggedfs
# immediately hangs up upon being mounted.
BROKEN_ON_PLATFORM+=	NetBSD-*-*

.if exists(/usr/include/sys/statvfs.h)
CPPFLAGS+=	-DHAVE_SYS_STATVFS_H
.endif

.if exists(/usr/include/sys/xattr.h)
CPPFLAGS+=	-DHAVE_SETXATTR
.endif

USE_LANGUAGES+=		c++
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/loggedfs ${DESTDIR}${PREFIX}/bin/loggedfs
	${INSTALL_MAN} ${WRKSRC}/loggedfs.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/loggedfs.1

.include "../../devel/librlog/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
