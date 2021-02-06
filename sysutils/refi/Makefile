# $NetBSD: Makefile,v 1.2 2021/02/06 10:42:51 pin Exp $

DISTNAME=	refi-3.0.0
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/miicat/refi/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gitlab.com/miicat/refi/
COMMENT=	Rename files in numberic order
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/refi-v3.0.0-99f2926da4561439c0ce95248344cd5c4f21de4d
USE_LANGUAGES+=	c	# rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/refi ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
