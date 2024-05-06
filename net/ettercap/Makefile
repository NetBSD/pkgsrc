# $NetBSD: Makefile,v 1.100 2024/05/06 08:40:30 jperkin Exp $

PKGREVISION= 8
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Suite for man in the middle attacks

CONFLICTS+=	ettercap-gtk-[0-9]*

CMAKE_ARGS+=	-DENABLE_GTK=OFF

.include "../../mk/bsd.pkg.mk"
