# $NetBSD: Makefile,v 1.41 2021/02/10 11:23:13 nia Exp $

DISTNAME=	scrot-1.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=resurrecting-open-source-projects/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/resurrecting-open-source-projects/scrot
COMMENT=	Command line screen capture util like "import", but using imlib2
LICENSE=	mit

GNU_CONFIGURE=	yes

.include "../../devel/giblib/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
