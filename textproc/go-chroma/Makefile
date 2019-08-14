# $NetBSD: Makefile,v 1.8 2019/08/14 15:45:49 bsiegert Exp $

DISTNAME=	chroma-0.5.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	7
MASTER_SITES=	${MASTER_SITE_GITHUB:=alecthomas/}
CATEGORIES=	textproc
GITHUB_PROJECT=	chroma
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alecthomas/chroma
COMMENT=	General purpose syntax highlighter in pure Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/alecthomas/chroma

.include "../../textproc/go-regexp2/buildlink3.mk"
.include "../../devel/go-fnmatch/buildlink3.mk"
.include "../../devel/go-colorable/buildlink3.mk"
.include "../../devel/go-kingpin.v3-unstable/buildlink3.mk"
.include "../../math/go-units/buildlink3.mk"
.include "../../devel/go-i18n/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
