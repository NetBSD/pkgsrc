# $NetBSD: Makefile,v 1.14 2024/04/25 12:29:44 nikita Exp $

DISTNAME=	1.8.1
PKGNAME=	passphrase-1.8.1
DIST_SUBDIR=	passphrase
CATEGORIES=	security
MASTER_SITES=	https://git.sr.ht/~alva/passphrase/archive/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~alva/passphrase
COMMENT=	Zero-dependency passphrase generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

ZIGBUILDARGS+=	-Dman-dir=${PKGMANDIR}

CONFLICTS+=	py[0-9]*-pyutil-[0-9]*

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
