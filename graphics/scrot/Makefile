# $NetBSD: Makefile,v 1.37 2019/11/10 11:21:59 nia Exp $

DISTNAME=	scrot-1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=resurrecting-open-source-projects/}
GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

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
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
