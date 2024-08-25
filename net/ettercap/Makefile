# $NetBSD: Makefile,v 1.103 2024/08/25 06:19:05 wiz Exp $

PKGREVISION= 10
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
