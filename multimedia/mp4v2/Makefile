# $NetBSD: Makefile,v 1.5 2018/07/18 00:06:22 joerg Exp $

DISTNAME=	mp4v2-3.0.3.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=TechSmith/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TechSmith/mp4v2
COMMENT=	Library for reading and modifying mp4 files
LICENSE=	mpl-1.1

GITHUB_TAG=	Release-MP4v2-${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/mp4v2-${GITHUB_TAG}

USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MAKE_FILE=		GNUmakefile

.include "../../mk/bsd.pkg.mk"
