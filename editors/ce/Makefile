# $NetBSD: Makefile,v 1.10 2004/12/03 15:14:56 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=		2

COMMENT+=		, tty version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

BUILD_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
