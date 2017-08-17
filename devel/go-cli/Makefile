# $NetBSD: Makefile,v 1.1 2017/08/17 01:19:56 gavan Exp $

DISTNAME=	cli-1.20.0
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=urfave/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/urfave/cli
COMMENT=	A simple, fast, and fun package for building command line apps in Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	gopkg.in/urfave/cli.v1

# Deal with renaming
pre-install:
	${MKDIR} ${WRKDIR}/src/github.com/urfave
	${MKDIR} ${WRKDIR}/pkg/${GO_PLATFORM}/github.com/urfave
	${CP} -R ${WRKDIR}/src/gopkg.in/urfave/cli.v1 ${WRKDIR}/src/github.com/urfave/cli
	${CP} -R ${WRKDIR}/pkg/${GO_PLATFORM}/gopkg.in/urfave/cli.v1 ${WRKDIR}/pkg/${GO_PLATFORM}/github.com/urfave/cli

.include "../../www/go-toml-burntsushi/buildlink3.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

