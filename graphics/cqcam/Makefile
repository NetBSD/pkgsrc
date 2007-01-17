# $NetBSD: Makefile,v 1.29 2007/01/17 02:25:45 rillig Exp $
#

DISTNAME=		cqcam-0.91
CATEGORIES=		graphics x11
MASTER_SITES=		http://www.cs.duke.edu/~reynolds/cqcam/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.duke.edu/~reynolds/cqcam/
COMMENT=		Free Color QuickCam control program

.include "../../mk/bsd.prefs.mk"

#NOT_FOR_UNPRIVILEGED=	yes	# seems to need setuid for everything
.if ${OPSYS} == "SunOS"
# Tries to install a device driver with unrestricted access to all
# hardware ports, which is also specific to i86pc platforms.
NOT_FOR_UNPRIVILEGED=	yes
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xview
USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		TCLCONFIG_SH=${TCLCONFIG_SH:Q}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
