# $NetBSD: Makefile,v 1.7 2018/11/04 18:38:00 bsiegert Exp $

DISTNAME=	jWalterWeatherman-20170523
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	0efa5202c04663c757d84f90f5219c1250baf94f
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/jwalterweatherman
COMMENT=	Seamless printing to the terminal and io.Writer
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/spf13/jwalterweatherman

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
