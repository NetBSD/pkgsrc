# $NetBSD: Makefile,v 1.1 2018/10/26 20:43:07 bsiegert Exp $

GITHUB_PROJECT=	hfst-ospell
DISTNAME=	hfstospell-0.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hfst/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/hfst/hfst-ospell/
COMMENT=	HFST spell checker library and command line tool
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++14

PKGCONFIG_OVERRIDE+=	hfstospell.pc.in

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
