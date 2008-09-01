# $NetBSD: Makefile,v 1.4 2008/09/01 12:24:54 tonnerre Exp $
#

DISTNAME=		bouml_${BOUMLVERSION}
PKGNAME=		bouml-${BOUMLVERSION}
CATEGORIES=		devel
MASTER_SITES=		http://bouml.free.fr/

MAINTAINER=		kcf@users.sourceforge.net
HOMEPAGE=		http://bouml.free.fr/
COMMENT=		UML modeling tool, generates C++, JAVA, and IDL

PKG_DESTDIR_SUPPORT=	user-destdir

BOUMLVERSION=		4.5

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pax
USE_LANGUAGES=		c++
BUILD_TARGET=		compile
USE_DIRS+=		xdg-1.3

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
