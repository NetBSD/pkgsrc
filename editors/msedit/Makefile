# $NetBSD: Makefile,v 1.1 2025/12/13 09:06:55 fox Exp $

DISTNAME=	edit-1.2.1
PKGNAME=	ms${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_PROJECT=	edit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/edit/
COMMENT=	Simple editor for simple needs
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

RUST_REQ=	1.87
MAKE_ENV+=	RUSTC_BOOTSTRAP=1

.include "cargo-depends.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/edit ${DESTDIR}${PREFIX}/bin/msedit

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
