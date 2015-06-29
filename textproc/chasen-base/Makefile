# $NetBSD: Makefile,v 1.24 2015/06/29 11:06:49 ryoon Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
CATEGORIES=		japanese textproc
MASTER_SITES=		${MASTER_SITE_OSDN:=chasen-legacy/56305/}

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://chasen-legacy.osdn.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf
OWN_DIRS=		${PREFIX}/${CHASEN_DICDIR}

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../textproc/chasen/Makefile.common"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/darts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
