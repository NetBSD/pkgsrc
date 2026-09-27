# $NetBSD: Makefile,v 1.116 2026/09/27 11:37:59 tnn Exp $

PKGREVISION= 3
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
