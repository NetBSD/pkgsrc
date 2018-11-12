# $NetBSD: Makefile,v 1.8 2018/11/12 03:51:53 ryoon Exp $

USE_GTK_VERSION=2

PKGREVISION= 6
.include "../../devel/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+2 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/-tools-/}

INSTALL_DIRS=	tools

.include "../../devel/libindicator/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
