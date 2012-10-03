# $NetBSD: Makefile,v 1.13.2.1 2012/10/03 12:07:40 spz Exp $
#

DISTNAME=	fusepod-0.5.1
PKGNAME=	fuse-pod-0.5.1
PKGREVISION=	12
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fusepod/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fusepod.sourceforge.net/
COMMENT=	FUSE-based filesystem for iPod

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

.include "../../audio/libgpod/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
