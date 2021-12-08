# $NetBSD: Makefile,v 1.95 2021/12/08 16:05:56 adam Exp $

PKGREVISION= 3
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
