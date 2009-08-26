# $NetBSD: Makefile,v 1.7 2009/08/26 19:57:20 sno Exp $
#

DISTNAME=		bouml_${BOUMLVERSION}
PKGNAME=		bouml-${BOUMLVERSION}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://bouml.free.fr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bouml.free.fr/
COMMENT=		UML modeling tool, generates C++, JAVA, and IDL

PKG_DESTDIR_SUPPORT=	user-destdir

BOUMLVERSION=		4.5

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pax
USE_LANGUAGES=		c++
BUILD_TARGET=		compile

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
