# $NetBSD: Makefile,v 1.11 2026/04/27 08:32:54 wiz Exp $

DISTNAME=	ncdu-2.9.2
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdu
LICENSE=	mit

USE_TOOLS+=	pkg-config

BROKEN=		"Needs an update for zig-0.16"

# Temporary required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/ncdu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
