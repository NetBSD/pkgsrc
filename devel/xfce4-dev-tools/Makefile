# $NetBSD: Makefile,v 1.37 2018/11/12 03:51:56 ryoon Exp $

PKGREVISION= 9
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-dev-tools-${XFCE4_VERSION}
CATEGORIES=	devel

HOMEPAGE=	http://users.xfce.org/~benny/projects/xfce4-dev-tools/
COMMENT=	Xfce development tools

GNU_CONFIGURE=	yes

USE_TOOLS+=	bash:run
REPLACE_BASH+=	scripts/xdt-commit

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../mk/bsd.pkg.mk"
