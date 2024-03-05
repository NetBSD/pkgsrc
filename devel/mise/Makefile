# $NetBSD: Makefile,v 1.2 2024/03/05 06:04:18 schmonz Exp $

DISTNAME=		mise-2024.3.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=jdx/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mise.jdx.dev/
COMMENT=		Polyglot tool version manager like asdf
LICENSE=		mit

USE_LANGUAGES=		c

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/man1/mise.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
