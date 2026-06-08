# $NetBSD: Makefile,v 1.3 2026/06/08 12:19:48 pin Exp $

DISTNAME=	doxx-0.1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgreenwell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bgreenwell/doxx/
COMMENT=	Show contents of .docx files on the terminal
LICENSE=	mit

BUILDLINK_TRANSFORM+=	rm:-Werror

CFLAGS+=		-Wno-implicit-function-declaration

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
