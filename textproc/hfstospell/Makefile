# $NetBSD: Makefile,v 1.13 2022/11/23 16:19:02 adam Exp $

GITHUB_PROJECT=	hfst-ospell
DISTNAME=	hfstospell-0.5.2
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=hfst/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/hfst/hfst-ospell/
COMMENT=	HFST spell checker library and command line tool
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config autoreconf autoconf automake aclocal
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11

PKGCONFIG_OVERRIDE+=	hfstospell.pc.in

pre-patch:
	cd ${WRKSRC} && autoreconf -vi

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
