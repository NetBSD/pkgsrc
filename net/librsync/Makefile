# $NetBSD: Makefile,v 1.9 2021/01/19 21:01:37 adam Exp $

DISTNAME=	librsync-2.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=librsync/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://librsync.sourcefrog.net/
COMMENT=	Rsync-like rolling checksum library
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl
TEST_TARGET=	test

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
