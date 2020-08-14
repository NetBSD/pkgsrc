# $NetBSD: Makefile,v 1.28 2020/08/14 20:01:29 bsiegert Exp $

DISTNAME=	pflag-1.0.5
PKGNAME=	go-${DISTNAME}
PKGREVISION=	3
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/pflag
COMMENT=	Replacement for flag package implementing POSIX --flags
LICENSE=	modified-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/spf13/pflag

REPLACE_BASH+=	verify/all.sh
REPLACE_BASH+=	verify/gofmt.sh
REPLACE_BASH+=	verify/golint.sh
USE_TOOLS+=	bash:run

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
