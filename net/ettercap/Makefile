# $NetBSD: Makefile,v 1.111 2026/01/07 08:48:15 wiz Exp $

PKGREVISION= 17
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GTK=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.pkg.mk"
