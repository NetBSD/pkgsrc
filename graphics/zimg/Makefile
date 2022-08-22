# $NetBSD: Makefile,v 1.1 2022/08/22 13:50:37 ast Exp $

DISTNAME=	zimg
PKGVERSION=	3.0.4
PKGNAME=	${DISTNAME}-${PKGVERSION}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=sekrit-twc/}
GITHUB_PROJECT=	zimg
GITHUB_TAG=	refs/tags/release-${PKGVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sekrit-twc/zimg
COMMENT=	"z" image processing library
LICENSE=	public-domain # "WTFPL" license: https://github.com/sekrit-twc/zimg/blob/master/COPYING

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}-release-${PKGVERSION_NOREV}

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	autoreconf autoconf automake

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
