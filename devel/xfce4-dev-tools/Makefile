# $NetBSD: Makefile,v 1.54 2023/11/12 13:21:13 wiz Exp $

PKGREVISION= 4
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.18.0
DISTNAME=	xfce4-dev-tools-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://archive.xfce.org/src/xfce/xfce4-dev-tools/${VERSION:R}/

HOMEPAGE=	http://users.xfce.org/~benny/projects/xfce4-dev-tools/
COMMENT=	Xfce development tools

USE_TOOLS+=	bash:run
REPLACE_BASH+=	helpers/xfce-build helpers/xfce-do-release
REPLACE_BASH+=	helpers/xfce-get-release-notes
REPLACE_BASH+=	helpers/xfce-get-translations helpers/xfce-update-news

GNU_CONFIGURE=	yes

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../mk/bsd.pkg.mk"
