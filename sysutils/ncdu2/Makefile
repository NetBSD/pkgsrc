# $NetBSD: Makefile,v 1.2 2023/02/28 22:55:40 wiz Exp $

DISTNAME=	ncdu-2.2.2
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdu
LICENSE=	mit

USE_TOOLS+=	pkg-config

# \todo: There is currently an issue building zig packages as RELRO.
RELRO_SUPPORTED=	no

# TODO: fix "make doc" or patch zig.build to install docs
post-build:
	mkdir ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/ncdu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
