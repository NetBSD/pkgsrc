# $NetBSD: Makefile,v 1.2 2016/08/03 10:22:11 adam Exp $

USE_GTK_VERSION=3

PKGREVISION= 1
.include "../../devel/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/3-/}

INSTALL_DIRS=	libindicator

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
