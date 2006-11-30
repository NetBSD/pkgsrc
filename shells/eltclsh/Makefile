# $NetBSD: Makefile,v 1.2 2006/11/30 18:02:28 joerg Exp $

DISTNAME=	eltclsh-1.6
PKGREVISION=	1
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
USE_TOOLS+=		gmake

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
