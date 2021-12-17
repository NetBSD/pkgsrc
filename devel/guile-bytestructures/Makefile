# $NetBSD: Makefile,v 1.5 2021/12/17 13:42:56 nikita Exp $

DISTNAME=	scheme-bytestructures-1.0.10
PKGNAME=	${DISTNAME:S/scheme/guile/}
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

.include "../../lang/guile22/module.mk"
.include "../../mk/bsd.pkg.mk"
