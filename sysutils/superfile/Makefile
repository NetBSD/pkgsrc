# $NetBSD: Makefile,v 1.3 2024/05/18 16:00:25 wiz Exp $

DISTNAME=	superfile-1.1.2
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
