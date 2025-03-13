# $NetBSD: Makefile,v 1.8 2025/03/13 19:36:14 vins Exp $

DISTNAME=	ncdu-2.7
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdu
LICENSE=	mit

USE_TOOLS+=	pkg-config

# Temporary required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/ncdu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
