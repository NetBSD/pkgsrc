# $NetBSD: Makefile,v 1.43 2026/01/29 13:57:32 wiz Exp $

DISTNAME=	qgpgme-2.0.0
CATEGORIES=	security
MASTER_SITES=	https://www.gnupg.org/ftp/gcrypt/qgpgme/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/software/gpgme/index.html
COMMENT=	Qt bindings for GPGME
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=2.0.0
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/gpgmepp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
