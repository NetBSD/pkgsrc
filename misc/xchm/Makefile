# $NetBSD: Makefile,v 1.87 2023/06/07 07:15:40 wiz Exp $

DISTNAME=	xchm-1.35
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rzvncj/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rzvncj/xCHM
COMMENT=	CHM viewer for UNIX
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/chmlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/wxGTK31/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
