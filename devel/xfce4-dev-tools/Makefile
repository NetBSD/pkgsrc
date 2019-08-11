# $NetBSD: Makefile,v 1.41 2019/08/11 13:20:52 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.13.0
DISTNAME=	xfce4-dev-tools-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://archive.xfce.org/src/xfce/xfce4-dev-tools/${VERSION:R}/

HOMEPAGE=	http://users.xfce.org/~benny/projects/xfce4-dev-tools/
COMMENT=	Xfce development tools

GNU_CONFIGURE=	yes

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../mk/bsd.pkg.mk"
