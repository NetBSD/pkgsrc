# $NetBSD: Makefile,v 1.102 2024/05/29 16:33:50 adam Exp $

PKGREVISION= 10
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
