# $NetBSD: Makefile,v 1.7 2018/04/16 14:34:20 wiz Exp $

USE_GTK_VERSION=2

PKGREVISION= 5
.include "../../devel/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+2 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/-tools-/}

INSTALL_DIRS=	tools

.include "../../devel/libindicator/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
