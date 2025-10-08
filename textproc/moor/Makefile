# $NetBSD: Makefile,v 1.11 2025/10/08 06:54:40 bsiegert Exp $

DISTNAME=		moor-2.5.0
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

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PKGBASE}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
