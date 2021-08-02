# $NetBSD: Makefile,v 1.3 2021/08/02 14:56:50 wiz Exp $

DISTNAME=	git-delta-0.8.3
CATEGORIES=	textproc
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dandavison/delta/
COMMENT=	Viewer for git and diff output
LICENSE=	mit

.include "cargo-depends.mk"
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/delta ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
