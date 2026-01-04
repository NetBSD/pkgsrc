# $NetBSD: Makefile,v 1.20 2026/01/04 13:47:59 wiz Exp $

DISTNAME=	1.8.1
PKGNAME=	passphrase-1.8.1
PKGREVISION=	2
DIST_SUBDIR=	passphrase-1
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/owl/passphrase/archive/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://codeberg.org/owl/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/passphrase

# Temporary required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=yes
# build.zig.zon:2:13: error: expected enum literal
#    .name = "passphrase",
# https://github.com/ziglang/zig/issues/20178
# project itself is archived:
# https://codeberg.org/owl/passphrase
# "I don't feel like keeping up with zig, so this is archived. Check out pp instead. https://codeberg.org/owl/pp"
BROKEN=		"Broken with zig-0.14"

ZIGBUILDARGS+=	-Dman-dir=${PKGMANDIR}

.include "zig-depends.mk"

CONFLICTS+=	py[0-9]*-pyutil-[0-9]*

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
