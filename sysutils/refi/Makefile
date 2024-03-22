# $NetBSD: Makefile,v 1.10 2024/03/22 08:26:48 pin Exp $

DISTNAME=	refi-3.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=miicat/}
GITLAB_PROJECT=	refi
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/miicat/refi/
COMMENT=	Rename files in numberic order
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/refi-v3.2.0-6530c47b177c916813bea899a9bca4eb502ba6f4

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/refi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
