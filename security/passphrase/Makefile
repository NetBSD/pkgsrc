# $NetBSD: Makefile,v 1.16 2024/04/26 11:09:57 nikita Exp $

DISTNAME=	1.8.1
PKGNAME=	passphrase-1.8.1
PKGREVISION=	1
DIST_SUBDIR=	passphrase-1
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
