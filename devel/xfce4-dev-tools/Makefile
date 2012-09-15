# $NetBSD: Makefile,v 1.18 2012/09/15 10:04:22 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.6.0
DISTNAME=	xfce4-dev-tools-${XFCE4_VERSION}
PKGREVISION=	9
CATEGORIES=	devel
COMMENT=	Xfce development tools
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS+=	bash:run
REPLACE_BASH+=	scripts/xdt-commit

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../mk/bsd.pkg.mk"
