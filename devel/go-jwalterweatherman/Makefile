# $NetBSD: Makefile,v 1.24 2020/06/17 09:54:05 bsiegert Exp $

DISTNAME=	jwalterweatherman-20181028
PKGNAME=	go-${DISTNAME}
PKGREVISION=	15
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	94f6ae3ed3bceceafa716478c5fbf8d29ca601a1
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/jwalterweatherman
COMMENT=	Seamless printing to the terminal and io.Writer
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/spf13/jwalterweatherman

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
