# $NetBSD: Makefile,v 1.32 2020/05/16 19:37:46 nia Exp $

DISTNAME=	viewnior-1.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hellosiyan/}
GITHUB_PROJECT=	Viewnior
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://siyanpanayotov.com/project/viewnior
COMMENT=	Viewnior is a fast and simple image viewer
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/Viewnior-${DISTNAME}

USE_TOOLS+=	pkg-config msgfmt xgettext
USE_LANGUAGES=	c c++

# XXX: msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../devel/meson/build.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
