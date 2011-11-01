# $NetBSD: Makefile,v 1.4 2011/11/01 06:50:28 sbd Exp $
#

DISTNAME=	archivemount-0.5.3
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	http://www.cybernoia.de/software/archivemount/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cybernoia.de/software/archivemount/
COMMENT=	FUSE gateway to libarchive

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/sys/statvfs.h)
CPPFLAGS+=	-DHAVE_STATVFS
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/archivemount ${DESTDIR}${PREFIX}/bin

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
