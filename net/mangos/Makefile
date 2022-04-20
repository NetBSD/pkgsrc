# $NetBSD: Makefile,v 1.1 2022/04/20 10:10:59 khorben Exp $

DISTNAME=	mangos-3.4.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}
CATEGORIES=	net
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nanomsg/mangos
COMMENT=	Pure Golang implementation of nanomsg's "Scalability Protocols"
LICENSE=	apache-2.0

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
