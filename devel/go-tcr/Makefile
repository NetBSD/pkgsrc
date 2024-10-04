# $NetBSD: Makefile,v 1.5 2024/10/04 16:26:33 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-1.2.0
PKGNAME=		go-${DISTNAME:tl}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=murex/}
GITHUB_PROJECT=		TCR
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/murex/TCR/
COMMENT=		TCR (Test and Commit or Revert) utility
LICENSE=		mit

WRKSRC=			${WRKDIR}/${DISTNAME}

GO_BUILD_PATTERN=	./src/...

INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
