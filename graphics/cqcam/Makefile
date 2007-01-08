# $NetBSD: Makefile,v 1.28 2007/01/08 04:51:44 rillig Exp $
#

DISTNAME=		cqcam-0.91
CATEGORIES=		graphics x11
MASTER_SITES=		http://www.cs.duke.edu/~reynolds/cqcam/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.duke.edu/~reynolds/cqcam/
COMMENT=		Free Color QuickCam control program

#NOT_FOR_UNPRIVILEGED=	yes	# seems to need setuid for everything

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		TCLCONFIG_SH=${TCLCONFIG_SH:Q}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
