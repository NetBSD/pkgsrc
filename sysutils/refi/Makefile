# $NetBSD: Makefile,v 1.8 2024/02/02 12:39:40 pin Exp $

DISTNAME=	refi-3.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=miicat/}
GITLAB_PROJECT=	refi
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/miicat/refi/
COMMENT=	Rename files in numberic order
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/refi-v3.1.2-9f794425760cd51f5dbf4b8def7dbceff4d47581

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/refi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
