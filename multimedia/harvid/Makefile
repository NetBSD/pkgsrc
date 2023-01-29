# $NetBSD: Makefile,v 1.13 2023/01/29 21:17:18 ryoon Exp $

DISTNAME=	harvid-0.8.3
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=x42/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://x42.github.com/harvid/
COMMENT=	HTTP Ardour Video Daemon
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config gmake

MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	libharvid/harvid.pc.in

MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	VERSION=${PKGVERSION_NOREV}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
