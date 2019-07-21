# $NetBSD: Makefile,v 1.10 2019/07/21 22:24:01 wiz Exp $

USE_GTK_VERSION=3

PKGREVISION= 9
.include "../../devel/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/3-/}

INSTALL_DIRS=	libindicator

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
