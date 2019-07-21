# $NetBSD: Makefile,v 1.36 2019/07/21 22:24:46 wiz Exp $
#

DISTNAME=	nestopia-1.49
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nestopiaue/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0ldsk00l.ca/nestopia/
COMMENT=	Portable, very accurate NES emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoreconf autoconf automake gawk pkg-config
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

AUTOCONF_REQD=	2.69
AUTOMAKE_REQD=	1.15

BUILD_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "options.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
