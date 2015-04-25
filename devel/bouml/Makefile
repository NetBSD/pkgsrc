# $NetBSD: Makefile,v 1.22 2015/04/25 14:20:32 tnn Exp $
#

DISTNAME=		bouml_${BOUMLVERSION}
PKGNAME=		bouml-${BOUMLVERSION}
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		http://bouml.free.fr/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bouml.fr/
COMMENT=		UML modeling tool, generates C++, JAVA, and IDL
LICENSE=                gnu-gpl-v2

BOUMLVERSION=		4.22.2

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pax
USE_LANGUAGES=		c++
BUILD_TARGET=		compile

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
