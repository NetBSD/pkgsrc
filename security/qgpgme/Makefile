# $NetBSD: Makefile,v 1.42 2026/01/07 08:48:45 wiz Exp $

DISTNAME=	gpgme-1.24.3
PKGNAME=	qgpgme-1.24.3
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=gpgme/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/related_software/gpgme/
COMMENT=	Qt bindings for GPGme
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
# QT6 needs std=c++17 set before configure test
CFLAGS+=	-std=c++17

BUILD_DIRS=	lang/qt/src

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
