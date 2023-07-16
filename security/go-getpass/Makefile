# $NetBSD: Makefile,v 1.1 2023/07/16 18:36:44 jschauma Exp $

DISTNAME=	getpass-0.2.1
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jschauma/}
CATEGORIES=	security
GITHUB_PROJECT=	getpass
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	https://github.com/jschauma/getpass
COMMENT=	a Go module to get a password
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/jschauma/getpass

post-build:
	rm -fr ${WRKDIR}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
