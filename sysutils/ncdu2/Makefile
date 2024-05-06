# $NetBSD: Makefile,v 1.7 2024/05/06 08:40:32 jperkin Exp $

DISTNAME=	ncdu-2.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdu
LICENSE=	mit

USE_TOOLS+=	pkg-config

# Temporary required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=yes

# TODO: fix "make doc" or patch zig.build to install docs
post-build:
	mkdir ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/ncdu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
