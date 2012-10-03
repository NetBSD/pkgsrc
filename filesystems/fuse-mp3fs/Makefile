# $NetBSD: Makefile,v 1.3 2012/10/03 16:08:32 asau Exp $
#

DISTNAME=	mp3fs-0.13
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3fs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3fs.sourceforge.net/
COMMENT=	MP3 transcoding FUSE file system
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config

INSTALLATION_DIRS=	share/doc/fuse-mp3fs

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/fuse-mp3fs

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
