# $NetBSD: Makefile,v 1.1 2025/12/30 11:06:20 kikadf Exp $

DISTNAME=	ndevd-25.12.09
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kikadf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/kikadf/ndevd/
COMMENT=	NetBSD devpubd + event forwarding to clients
LICENSE=	original-bsd

USE_TOOLS+=	sed

NO_CONFIGURE=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		MANDIR=${PREFIX}/${PKGMANDIR}/man8

# Based on drvctl(4)
ONLY_FOR_PLATFORM=	NetBSD-*-*

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
