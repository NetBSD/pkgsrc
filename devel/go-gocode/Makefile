# $NetBSD: Makefile,v 1.79.2.1 2026/04/22 14:31:58 maya Exp $

DISTNAME=	gocode-20170907
PKGNAME=	go-${DISTNAME}
PKGREVISION=	79
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
