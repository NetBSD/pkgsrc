# $NetBSD: Makefile,v 1.26 2025/08/25 08:35:12 wiz Exp $
#

PKGNAME=	qoauth-1.0.1
DISTNAME=	${PKGNAME_NOREV}-src
PKGREVISION=	20
CATEGORIES=	security
#MASTER_SITES=	http://files.ayoy.net/qoauth/release/1.0.1/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://files.ayoy.net/qoauth/release/1.0.1/src/
COMMENT=	OAuth library for Qt
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake PREFIX=${PREFIX}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
