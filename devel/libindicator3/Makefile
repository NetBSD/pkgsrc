# $NetBSD: Makefile,v 1.6 2018/03/12 11:15:30 wiz Exp $

USE_GTK_VERSION=3

PKGREVISION= 5
.include "../../devel/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/3-/}

INSTALL_DIRS=	libindicator

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
