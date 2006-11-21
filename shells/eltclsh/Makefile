# $NetBSD: Makefile,v 1.1.1.1 2006/11/21 15:27:42 obache Exp $

DISTNAME=	eltclsh-1.6
CATEGORIES=	shells
MASTER_SITES=	http://softs.laas.fr/openrobots/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://softs.laas.fr/openrobots/tools/eltclsh.php
COMMENT=	Interactive TCL shell with editline facilities

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake groff

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
