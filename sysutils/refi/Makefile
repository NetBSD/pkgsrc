# $NetBSD: Makefile,v 1.4 2021/08/07 20:45:32 pin Exp $

DISTNAME=	refi-3.1.0
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/miicat/refi/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gitlab.com/miicat/refi/
COMMENT=	Rename files in numberic order
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/refi-v3.1.0-7e9296b5259eefce9d46255219d004bfa7cb083d

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/refi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
