# $NetBSD: Makefile,v 1.2 2017/01/19 18:52:06 agc Exp $

DISTNAME=	libfreefare-0.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nfc-tools/libfreefare/releases/download/${DISTNAME}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nfc-tools.org/index.php?title=Libfreefare
COMMENT=	Convenient API for MIFARE card manipulations
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

.include "../../devel/libnfc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
