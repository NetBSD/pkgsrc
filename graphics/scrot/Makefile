# $NetBSD: Makefile,v 1.39 2020/11/24 17:13:08 nia Exp $

DISTNAME=	scrot-1.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=resurrecting-open-source-projects/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/resurrecting-open-source-projects/scrot
COMMENT=	Commandline screen capture util like "import", but using imlib2
LICENSE=	mit

TOOL_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

USE_TOOLS+=	autoreconf automake m4

GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/giblib/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
