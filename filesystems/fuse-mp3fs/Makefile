# $NetBSD: Makefile,v 1.4 2014/11/23 19:33:16 wiz Exp $

DISTNAME=	mp3fs-0.91
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	https://github.com/khenriks/mp3fs/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://khenriks.github.io/mp3fs/
COMMENT=	MP3 transcoding FUSE file system
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config

INSTALLATION_DIRS=	share/doc/fuse-mp3fs

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/fuse-mp3fs

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
