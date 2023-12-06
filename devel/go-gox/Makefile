# $NetBSD: Makefile,v 1.49.2.2 2023/12/06 12:08:40 spz Exp $
#

DISTNAME=		gox-1.0.1
PKGNAME=		go-${DISTNAME}
PKGREVISION=		48
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mitchellh/}
GITHUB_PROJECT=		gox
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mitchellh/gox
COMMENT=		Tool for go cross compilation
LICENSE=		mpl-2.0

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
