# $NetBSD: Makefile,v 1.2 2023/10/22 19:38:12 pin Exp $

DISTNAME=	tlrc-1.6.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=acuteenvy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/acuteenvy/tlrc/
COMMENT=	Tldr client written in Rust
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/tldr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tldr.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
