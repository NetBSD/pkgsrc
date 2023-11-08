# $NetBSD: Makefile,v 1.99 2023/11/08 13:20:23 wiz Exp $

PKGREVISION= 7
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
