# $NetBSD: Makefile,v 1.9 2004/10/03 00:14:38 tv Exp $
#

.include "Makefile.common"
PKGREVISION=		2

COMMENT+=		, tty version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

ALL_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
