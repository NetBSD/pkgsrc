# $NetBSD: Makefile,v 1.4 2003/07/17 22:54:11 grant Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
CATEGORIES=		japanese textproc
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/chasen/

PATCHFILES=		chasen-${CHASEN_VERSION}-nmz.diff
PATCH_SITES=		${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://chasen.aist-nara.ac.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
OWN_DIRS=		${CHASEN_DICDIR}

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../chasen/Makefile.common"
.include "../../mk/bsd.pkg.mk"
