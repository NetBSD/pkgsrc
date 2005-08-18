# $NetBSD: Makefile,v 1.12 2005/08/18 15:37:17 taca Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
PKGREVISION=		2
CATEGORIES=		japanese textproc
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/chasen/

PATCHFILES=		chasen-2.3.3.20030821.patch \
			chasen-2.3.3.20030822.patch
PATCH_SITES=		${MASTER_SITES}

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://chasen.aist-nara.ac.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System

GNU_CONFIGURE=		yes
USE_LANGUAGE=		c c++
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
OWN_DIRS=		${CHASEN_DICDIR}

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../chasen/Makefile.common"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/darts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
