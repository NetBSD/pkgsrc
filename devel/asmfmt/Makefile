# $NetBSD: Makefile,v 1.1 2020/12/06 16:14:07 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	asmfmt-1.2.1
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
