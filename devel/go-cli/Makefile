# $NetBSD: Makefile,v 1.25 2020/06/17 09:54:03 bsiegert Exp $

DISTNAME=	cli-1.20.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	20
MASTER_SITES=	${MASTER_SITE_GITHUB:=urfave/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/urfave/cli
COMMENT=	Package for building command line apps in Go
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	gopkg.in/urfave/cli.v1

REPLACE_BASH+=		autocomplete/bash_autocomplete
REPLACE_PYTHON+=	generate-flag-types
REPLACE_PYTHON+=	runtests
USE_TOOLS+=		bash:run

# Deal with renaming
pre-install:
	${MKDIR} ${WRKDIR}/src/github.com/urfave
	${MKDIR} ${WRKDIR}/pkg/${GO_PLATFORM}/github.com/urfave
	${CP} -R ${WRKDIR}/src/gopkg.in/urfave/cli.v1 ${WRKDIR}/src/github.com/urfave/cli
	${CP} -R ${WRKDIR}/pkg/${GO_PLATFORM}/gopkg.in/urfave/cli.v1 ${WRKDIR}/pkg/${GO_PLATFORM}/github.com/urfave/cli

.include "../../www/go-toml-burntsushi/buildlink3.mk"
.include "../../devel/go-yaml/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
