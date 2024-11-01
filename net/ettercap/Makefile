# $NetBSD: Makefile,v 1.105 2024/11/01 12:53:49 wiz Exp $

PKGREVISION= 12
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
