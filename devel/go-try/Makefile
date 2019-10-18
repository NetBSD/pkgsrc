# $NetBSD: Makefile,v 1.10 2019/10/18 14:58:52 bsiegert Exp $

DISTNAME=	try-1.0.0.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	9
MASTER_SITES=	${MASTER_SITE_GITHUB:=matryer/}
CATEGORIES=	devel
GITHUB_PROJECT=	try
GITHUB_TAG=	9ac251b645a2628ef89dbd2986987cc1299408ff

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matryer/try
COMMENT=	Idiomatic Go retry package
ICENSE=		mit

GO_DIST_BASE=	try-${GITHUB_TAG}
GO_SRCPATH=	github.com/matryer/try

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
