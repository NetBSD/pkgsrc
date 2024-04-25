# $NetBSD: Makefile,v 1.15 2024/04/25 22:31:24 nikita Exp $

DISTNAME=	1.8.1
PKGNAME=	passphrase-1.8.1
DIST_SUBDIR=	passphrase
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/owl/passphrase/archive/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://codeberg.org/owl/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/passphrase

ZIGBUILDARGS+=	-Dman-dir=${PKGMANDIR}

CONFLICTS+=	py[0-9]*-pyutil-[0-9]*

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
