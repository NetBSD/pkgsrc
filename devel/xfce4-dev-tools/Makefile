# $NetBSD: Makefile,v 1.16 2012/03/03 00:14:25 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	4.6.0
DISTNAME=	xfce4-dev-tools-${XFCE4_VERSION}
PKGREVISION=	7
CATEGORIES=	devel
COMMENT=	Xfce development tools
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS+=	bash:run
REPLACE_BASH+=	scripts/xdt-commit

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../mk/bsd.pkg.mk"
