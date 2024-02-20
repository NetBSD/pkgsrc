# $NetBSD: Makefile,v 1.9 2024/02/20 21:33:05 pin Exp $

DISTNAME=	refi-3.1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=miicat/}
GITLAB_PROJECT=	refi
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/miicat/refi/
COMMENT=	Rename files in numberic order
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/refi-v3.1.3-8bed8fcb954cc78e5f398144c654ba4e804a1d10

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/refi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
