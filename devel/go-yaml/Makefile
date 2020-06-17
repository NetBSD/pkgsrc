# $NetBSD: Makefile,v 1.24 2020/06/17 09:54:04 bsiegert Exp $

DISTNAME=	yaml-0.0.20160301
PKGNAME=	go-${DISTNAME}
PKGREVISION=	19
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-yaml/}
CATEGORIES=	devel
GITHUB_TAG=	a83829b6f1293c91addabc89d0571c246397bbf4
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gopkg.in/yaml.v2
COMMENT=	YAML support for the Go language
LICENSE=	gnu-lgpl-v3

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	gopkg.in/yaml.v2

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
