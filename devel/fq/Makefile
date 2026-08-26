# $NetBSD: Makefile,v 1.54 2026/08/26 09:31:37 wiz Exp $

DISTNAME=	fq-0.18.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wader/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wader/fq/
COMMENT=	File parsing tool like jq, but for binary files
LICENSE=	mit

GO_BUILD_PATTERN+=	.

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/fq.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
