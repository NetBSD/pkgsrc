# $NetBSD: Makefile,v 1.9 2017/08/16 20:45:36 wiz Exp $
#

DISTNAME=	archivemount-0.5.3
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	filesystems
#MASTER_SITES=	http://www.cybernoia.de/software/archivemount/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cybernoia.de/software/archivemount/
COMMENT=	FUSE gateway to libarchive

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
