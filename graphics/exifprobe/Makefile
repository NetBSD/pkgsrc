# $NetBSD: Makefile,v 1.9 2022/08/19 01:01:28 tnn Exp $
#

DISTNAME=		exifprobe-2.1.0.20201230
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=hfiguiere/}
GITHUB_TAG=		eee65ff3c62fed3fff35e690230820bd80c90381

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hfiguiere/exifprobe
COMMENT=	EXIF data extractor
LICENSE=	modified-bsd

# byteorder.h problems
MAKE_JOBS_SAFE=	no

CFLAGS.SunOS+=		-Du_int32_t=uint32_t

INSTALL_MAKE_FLAGS=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
