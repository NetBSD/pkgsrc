# $NetBSD: Makefile,v 1.6 2004/05/06 13:32:38 taca Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
CATEGORIES=		japanese textproc
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/chasen/

PATCHFILES=		chasen-2.3.3.20030821.patch \
			chasen-2.3.3.20030822.patch \
			chasen-2.3.3.20031024.patch
PATCH_SITES=		${MASTER_SITES}
#PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://chasen.aist-nara.ac.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System

GNU_CONFIGURE=		yes
USE_LANGUAGE=		c c++
USE_LIBTOOL=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
OWN_DIRS=		${CHASEN_DICDIR}

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../chasen/Makefile.common"
.include "../../textproc/darts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
