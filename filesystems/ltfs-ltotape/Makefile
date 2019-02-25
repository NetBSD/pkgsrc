# $NetBSD: Makefile,v 1.1 2019/02/25 01:00:39 manu Exp $

GITHUB_PROJECT=	ltfs-backends
DISTNAME=	v0.1
PKGNAME=	ltfs-ltotape-${DISTNAME:S/v//}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=LinearTapeFileSystem/}/${GITHUB_PROJECT}/archive/
DIST_SUBDIR=	${GITHUB_PROJECT}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME:S/v//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LinearTapeFileSystem/ltfs-backends/
COMMENT=	HPE ltotape tape backend for LTFS
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config
USE_LANGUAGES=	c

CPPFLAGS.NetBSD+=	-D_KERNTYPES

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../filesystems/ltfs/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
