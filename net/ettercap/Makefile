# $NetBSD: Makefile,v 1.108 2025/04/19 07:58:08 wiz Exp $

PKGREVISION= 15
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
