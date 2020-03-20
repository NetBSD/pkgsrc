# $NetBSD: Makefile,v 1.37 2020/03/20 11:57:37 nia Exp $
#

DISTNAME=	fusepod-0.5.1
PKGNAME=	fuse-pod-0.5.1
PKGREVISION=	32
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fusepod/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fusepod.sourceforge.net/
COMMENT=	FUSE-based filesystem for iPod

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

.include "../../audio/libgpod/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
