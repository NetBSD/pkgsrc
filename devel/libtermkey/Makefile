# $NetBSD: Makefile,v 1.1 2022/04/20 17:41:08 nia Exp $

DISTNAME=	libtermkey-0.22
CATEGORIES=	devel
MASTER_SITES=	https://www.leonerd.org.uk/code/libtermkey/

HOMEPAGE=	https://www.leonerd.org.uk/code/libtermkey/
COMMENT=	Library to process keyboard entry from terminal-based programs
LICENSE=	mit

USE_TOOLS+=	pkg-config gmake gzip
USE_LIBTOOL=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

MANCOMPRESSED=	yes

PKGCONFIG_OVERRIDE+=	termkey.pc.in

.include "../../devel/unibilium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
