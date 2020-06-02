# $NetBSD: Makefile,v 1.13 2020/06/02 08:22:55 adam Exp $

DISTNAME=	gpgme-1.10.0
PKGNAME=	qgpgme-1.10.0
PKGREVISION=	11
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gpgme/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/related_software/gpgme/
COMMENT=	Qt bindings for GPGme
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

BUILD_DIRS=	lang/qt/src

CONFIGURE_ENV+=	MOC=${QTDIR}/bin/moc

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
