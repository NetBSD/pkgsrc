# $NetBSD: Makefile,v 1.38 2025/04/17 21:52:19 wiz Exp $

DISTNAME=	gpgme-1.23.2
PKGNAME=	qgpgme-1.23.2
PKGREVISION=	7
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

BUILD_DIRS=	lang/qt/src

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
