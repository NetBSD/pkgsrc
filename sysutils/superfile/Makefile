# $NetBSD: Makefile,v 1.22.2.1 2026/07/14 00:36:06 maya Exp $

DISTNAME=	superfile-1.1.2
PKGREVISION=	20
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=MHNightCat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MHNightCat/superfile/
COMMENT=	Pretty fancy and modern terminal file manager
LICENSE=	mit

USE_LANGUAGES=	c

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GO_MODULE_EXTRACT+=	github.com_barasher_go-exiftool_@v_v1.10.0.zip

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
