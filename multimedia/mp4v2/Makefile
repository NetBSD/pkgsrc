# $NetBSD: Makefile,v 1.9 2021/04/13 16:32:09 adam Exp $

DISTNAME=	mp4v2-4.1.6
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=TechSmith/}
GITHUB_TAG=	Release-ThirdParty-MP4v2-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TechSmith/mp4v2
COMMENT=	Library for reading and modifying mp4 files
LICENSE=	mpl-1.1

WRKSRC=		${WRKDIR}/mp4v2-${GITHUB_TAG}

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
MAKE_FILE=		GNUmakefile

.include "../../mk/bsd.pkg.mk"
