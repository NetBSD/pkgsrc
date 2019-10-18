# $NetBSD: Makefile,v 1.5 2019/10/18 14:58:52 bsiegert Exp $
#

NAME=			gox
VERSION=		1.0.1
DISTNAME=		${NAME}-${VERSION}
PKGNAME=		go-${DISTNAME}
PKGREVISION=		2
GITHUB_PROJECT=		${NAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mitchellh/}
GITHUB_TAG=		v${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mitchellh/gox
COMMENT=		Tool for go cross compilation
LICENSE=		mpl-2.0

GO_SRCPATH=		github.com/mitchellh/gox
GO_DIST_BASE=		${DISTNAME}*

DEPENDS+=		go-iochan-[0-9]*:../../devel/go-iochan

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
