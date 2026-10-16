# $NetBSD: Makefile,v 1.1 2026/10/16 17:20:59 leot Exp $

DISTNAME=	agg-1.9.0
PKGNAME=	${DISTNAME:S/^/asciinema-/}
CATEGORIES=	misc multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=asciinema/}
GITHUB_PROJECT=	agg
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/asciinema/agg
COMMENT=	Asciinema gif generator
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/agg ${DESTDIR}${PREFIX}/bin/asciinema-agg

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
