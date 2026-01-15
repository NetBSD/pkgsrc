# $NetBSD: Makefile,v 1.77 2026/01/15 19:54:40 bsiegert Exp $

DISTNAME=	gocode-20170907
PKGNAME=	go-${DISTNAME}
PKGREVISION=	76
MASTER_SITES=	${MASTER_SITE_GITHUB:=nsf/}
CATEGORIES=	devel
GITHUB_PROJECT=	gocode
GITHUB_TAG=	v.${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/nsf/gocode
COMMENT=	Autocompletion daemon for Go
LICENSE=	mit

WRKSRC=		${WRKDIR}/gocode-${GITHUB_TAG}

post-extract:
	${CP} ${FILESDIR}/go.mod ${WRKSRC}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
