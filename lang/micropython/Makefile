# $NetBSD: Makefile,v 1.1 2016/01/18 07:54:51 agc Exp $

DISTNAME=	micropython-1.5.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=micropython/}
GITHUB_TAG=	v1.5.2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://micropython.org/
COMMENT=	Embedded version of python
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
DIST_SUBDIR=	${PKGNAME_NOREV}

USE_TOOLS+=	gmake pkg-config

AUTO_MKDIRS=	yes

.include "../../devel/libffi/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
