# $NetBSD: Makefile,v 1.19 2004/01/03 18:49:46 reed Exp $

DISTNAME=		gperiodic-2.0.7
PKGREVISION=		1
CATEGORIES=		misc x11
MASTER_SITES=		http://www.acclab.helsinki.fi/~frantz/software/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.acclab.helsinki.fi/~frantz/software/gperiodic.php
COMMENT=		Displays a periodic table of the elements

BUILD_USES_MSGFMT=	# defined
DEPENDS+=		gnome1-dirs>=1.0:../../misc/gnome1-dirs

USE_BUILDLINK2=		# defined
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
USE_GMAKE=		# defined

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
ALL_TARGET=		gperiodic

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
