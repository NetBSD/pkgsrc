# $NetBSD: Makefile,v 1.9 2018/11/14 22:21:17 kleink Exp $

USE_GTK_VERSION=3

PKGREVISION= 8
.include "../../devel/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/3-/}

INSTALL_DIRS=	libindicator

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
