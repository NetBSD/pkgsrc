# $NetBSD: Makefile,v 1.6 2012/09/11 23:25:08 asau Exp $

DISTNAME=	eltclsh-1.9
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://softs.laas.fr/openrobots/php/download.php/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://softs.laas.fr/openrobots/wiki/eltclsh
COMMENT=	Interactive TCL shell with editline facilities

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "options.mk"

INSTALL_ENV+=		ELTCL_LIBRARY=${DESTDIR}${PREFIX}/share/eltcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
