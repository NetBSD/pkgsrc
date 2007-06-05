# $NetBSD: Makefile,v 1.1.1.1 2007/06/05 05:56:42 rillig Exp $
#

DISTNAME=		bouml_${BOUMLVERSION}
PKGNAME=		bouml-${BOUMLVERSION}
CATEGORIES=		devel
MASTER_SITES=		http://bouml.free.fr/

MAINTAINER=		kcf@users.sourceforge.net
HOMEPAGE=		http://bouml.free.fr/
COMMENT=		UML modeling tool, generates C++, JAVA, and IDL

BOUMLVERSION=		2.27

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
USE_LANGUAGES=		c++
BUILD_TARGET=		compile
USE_DIRS+=		xdg-1.3

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
