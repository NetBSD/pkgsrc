# $NetBSD: Makefile,v 1.15 2022/10/06 22:39:51 rin Exp $

DISTNAME=	eltclsh-1.9
PKGREVISION=	7
CATEGORIES=	shells
MASTER_SITES=	http://softs.laas.fr/openrobots/php/download.php/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://softs.laas.fr/openrobots/wiki/eltclsh
COMMENT=	Interactive TCL shell with editline facilities

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

MAKE_JOB_SAFE=		no

.include "options.mk"

INSTALL_ENV+=		ELTCL_LIBRARY=${DESTDIR}${PREFIX}/share/eltcl

.include "../../devel/editline/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
