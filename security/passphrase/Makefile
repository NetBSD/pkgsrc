# $NetBSD: Makefile,v 1.19 2024/05/05 20:56:55 nikita Exp $

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

ZIGBUILDARGS+=	-Dman-dir=${PKGMANDIR}

.include "zig-depends.mk"

CONFLICTS+=	py[0-9]*-pyutil-[0-9]*

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
