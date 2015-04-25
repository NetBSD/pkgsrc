# $NetBSD: Makefile,v 1.26 2015/04/25 14:23:29 tnn Exp $
#

DISTNAME=	extcalc-0.9.3-1
PKGNAME=	extcalc-0.9.3
PKGREVISION=	21
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=extcalc-linux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://extcalc-linux.sourceforge.net/
COMMENT=	Scientific graphic calculator

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
LDFLAGS+=	-lGL	# direct link required by ld v2.22

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
