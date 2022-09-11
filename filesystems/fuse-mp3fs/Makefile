# $NetBSD: Makefile,v 1.9 2022/09/11 12:51:36 wiz Exp $
#

DISTNAME=	mp3fs-1.1.1
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=khenriks/}
GITHUB_PROJECT=	mp3fs
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3fs.sourceforge.net/
COMMENT=	MP3 transcoding FUSE file system
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS=	pkg-config gmake

.include "options.mk"

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
