# $NetBSD: Makefile,v 1.9 2023/09/13 08:10:40 pin Exp $

DISTNAME=	hexyl-0.13.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sharkdp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sharkdp/hexyl/
COMMENT=	Command-line hex viewer
LICENSE=	apache-2.0

TOOL_DEPENDS+=	go-md2man-[0-9]*:../../textproc/go-md2man

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

# Use go-md2man to generate manpages and install them
post-install:
	go-md2man < ${WRKSRC}/doc/hexyl.1.md > ${WRKSRC}/doc/hexyl.1
	${INSTALL_MAN} ${WRKSRC}/doc/hexyl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
