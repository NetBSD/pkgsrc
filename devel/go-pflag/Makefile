# $NetBSD: Makefile,v 1.14 2019/04/16 18:41:16 bsiegert Exp $

DISTNAME=	pflag-1.0.1
PKGNAME=	go-${DISTNAME}
PKGREVISION=	6
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=     v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

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
