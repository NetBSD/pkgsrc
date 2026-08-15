# $NetBSD: Makefile,v 1.44 2026/08/15 12:53:37 bsiegert Exp $

DISTNAME=		moor-2.16.2
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=walles/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/walles/moor/
COMMENT=		Pager designed to just do the right thing without any configuration
LICENSE=		2-clause-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "go-modules.mk"

GOFLAGS=		-ldflags "-X main.versionString=${PKGVERSION_NOREV}"

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PKGBASE}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
