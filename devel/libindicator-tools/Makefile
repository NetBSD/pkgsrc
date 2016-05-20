# $NetBSD: Makefile,v 1.1 2016/05/20 22:23:43 youri Exp $

USE_GTK_VERSION=2

.include "../../devel/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+2 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/-tools-/}

INSTALL_DIRS=	tools

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
