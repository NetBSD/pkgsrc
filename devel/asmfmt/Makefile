# $NetBSD: Makefile,v 1.3 2021/03/19 17:36:47 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	asmfmt-1.2.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=klauspost/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/klauspost/asmfmt/
COMMENT=	Go assembler formatter
LICENSE=	mit

GO_SRCPATH=		github.com/klauspost/asmfmt
GO_DIST_BASE=		${DISTNAME}
GO_BUILD_PATTERN=	github.com/klauspost/asmfmt/cmd/asmfmt

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/asmfmt ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
