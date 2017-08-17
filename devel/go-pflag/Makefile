# $NetBSD: Makefile,v 1.1 2017/08/17 01:36:26 gavan Exp $

DISTNAME=	pflag-1.0.0
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=     v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/pflag
COMMENT=	Drop-in replacement for Go's flag package, implementing POSIX/GNU-style --flags.
LICENSE=	modified-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/spf13/pflag

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

