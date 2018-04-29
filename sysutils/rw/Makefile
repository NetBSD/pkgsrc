# $NetBSD: Makefile,v 1.1 2018/04/29 14:22:35 kamil Exp $

DISTNAME=	rw-portable-1.0
PKGNAME=	${DISTNAME:S/-portable//}
CATEGORIES=	sysutils
MASTER_SITES=	https://sortix.org/rw/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sortix.org/rw/
COMMENT=	Sortix dd(1) replacement
LICENSE=	isc

INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
