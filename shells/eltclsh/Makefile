# $NetBSD: Makefile,v 1.19 2023/12/22 18:30:10 zafer Exp $

DISTNAME=	eltclsh-1.9
PKGREVISION=	9
CATEGORIES=	shells
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://softs.laas.fr/openrobots/wiki/eltclsh
COMMENT=	Interactive TCL shell with editline facilities

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "options.mk"

INSTALL_ENV+=		ELTCL_LIBRARY=${DESTDIR}${PREFIX}/share/eltcl

.include "../../devel/editline/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
