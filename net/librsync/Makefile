# $NetBSD: Makefile,v 1.6 2018/08/22 09:45:54 wiz Exp $

DISTNAME=	librsync-2.0.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=librsync/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librsync.sourcefrog.net/
COMMENT=	rsync-like rolling checksum library
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	perl
USE_LANGUAGES=	c c++

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
