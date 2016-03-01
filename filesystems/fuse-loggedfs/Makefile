# $NetBSD: Makefile,v 1.7 2016/03/01 20:16:17 joerg Exp $
#

DISTNAME=	loggedfs-0.4
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=loggedfs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_SOURCEFORGE:=loggedfs/}
COMMENT=	FUSE file system which logs all operations

CPPFLAGS.NetBSD+=	-D_KERNTYPES

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
