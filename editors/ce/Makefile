# $NetBSD: Makefile,v 1.11 2005/01/08 07:46:15 schmonz Exp $
#

.include "Makefile.common"

COMMENT+=		, tty version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

BUILD_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
