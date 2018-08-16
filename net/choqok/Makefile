# $NetBSD: Makefile,v 1.40 2018/08/16 18:55:06 adam Exp $
#

DISTNAME=	choqok-1.5
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=choqok/}Choqok/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
#HOMEPAGE=	http://choqok.gnufolks.org/
COMMENT=	Twitter and StatusNet client for KDE
LICENSE=	gnu-gpl-v2

# /data/scratch/net/choqok/work/choqok-1.4/plugins/shorteners/bit_ly/bit_ly_settings.h:64:5: error: unterminated /* comment
MAKE_JOBS_SAFE=	no

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl msgfmt pkg-config

BUILD_DEPENDS+=         automoc4>=0.9.87:../../devel/automoc4
DEPENDS=	qca2-ossl-[0-9]*:../../security/qca2-ossl

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../security/qoauth/buildlink3.mk"
.include "../../misc/attica/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
