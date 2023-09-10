# $NetBSD: Makefile,v 1.8 2023/09/10 18:34:07 pin Exp $

DISTNAME=	hexyl-0.13.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/hexyl/
COMMENT=	Command-line hex viewer
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-build:
	${CP} ${FILESDIR}/hexyl.1 ${WRKDIR}/hexyl.1

post-install:
	${INSTALL_MAN} ${WRKDIR}/hexyl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
