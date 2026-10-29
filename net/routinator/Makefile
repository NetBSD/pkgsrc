# $NetBSD: Makefile,v 1.16 2026/10/29 19:47:04 drixter Exp $

VER=		0.15.3
DISTNAME=	routinator-${VER}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=NLnetLabs/}
GITHUB_TAG=	v${VER}
GITHUB_PROJECT=	routinator

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/NLnetLabs/routinator
COMMENT=	Validate RPKI ROA against routing announcements
LICENSE=	modified-bsd

# 0.13.0 requires minimum this rust version:
RUST_REQ=		1.74.0

.include "cargo-depends.mk"

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR} ${EGDIR}

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/routinator \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/./etc/routinator.conf.example \
		${DESTDIR}${EGDIR}

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
