# $NetBSD: Makefile,v 1.6 2022/03/14 15:39:07 nikita Exp $

DISTNAME=	scheme-bytestructures-1.0.10
PKGNAME=	${DISTNAME:S/scheme/guile/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=TaylanUB/}
GITHUB_PROJECT=	scheme-bytestructures
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/TaylanUB/scheme-bytestructures/
COMMENT=	Structured access to bytevector contents
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

GUILE_NEED_BOOTSTRAP=	yes

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
