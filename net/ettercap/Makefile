# $NetBSD: Makefile,v 1.96 2022/10/26 10:31:46 wiz Exp $

PKGREVISION= 4
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
