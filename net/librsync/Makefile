# $NetBSD: Makefile,v 1.3 2016/09/01 16:16:55 wiz Exp $

DISTNAME=	librsync-2.0.0
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

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
