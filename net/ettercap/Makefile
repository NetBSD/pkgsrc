# $NetBSD: Makefile,v 1.104 2024/11/01 00:53:03 wiz Exp $

PKGREVISION= 11
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
