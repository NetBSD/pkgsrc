# $NetBSD: Makefile,v 1.6 2022/02/25 09:14:41 pin Exp $

DISTNAME=	refi-3.1.1
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/miicat/refi/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/miicat/refi/
COMMENT=	Rename files in numberic order
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/refi-v3.1.1-5fb659012fd8332404736012f4c6bc4ccdf1771c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/refi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
