# $NetBSD: Makefile,v 1.10 2026/11/23 12:24:14 pin Exp $

DISTNAME=	MovieBox-Tui-0.1.30
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=mesamirh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mesamirh/MovieBox-Tui/
COMMENT=	TUI to find, download and stream on local mediaplayers
LICENSE=	apache-2.0 OR mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/MovieBox-Tui-0.1.30
RUST_REQ=	1.90

DEPENDS+=	mpv-[0-9]*:../../multimedia/mpv

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
