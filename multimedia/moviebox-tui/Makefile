# $NetBSD: Makefile,v 1.5 2026/10/28 18:01:46 pin Exp $

DISTNAME=	MovieBox-Tui-0.1.27
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=mesamirh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mesamirh/MovieBox-Tui/
COMMENT=	TUI to find, download and stream on local mediaplayers
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/MovieBox-Tui-0.1.27
RUST_REQ=	1.90.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../multimedia/mpv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
