# $NetBSD: Makefile,v 1.23 2004/04/24 22:46:11 jlam Exp $

DISTNAME=		gperiodic-2.0.7
PKGREVISION=		2
CATEGORIES=		misc x11
MASTER_SITES=		http://www.acclab.helsinki.fi/~frantz/software/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.acclab.helsinki.fi/~frantz/software/gperiodic.php
COMMENT=		Displays a periodic table of the elements

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK2=		# defined
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
USE_GNU_TOOLS+=		make

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
ALL_TARGET=		gperiodic

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
