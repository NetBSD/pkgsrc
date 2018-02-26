# $NetBSD: Makefile,v 1.1 2018/02/26 16:52:21 leot Exp $

DISTNAME=	sacc-v1.00
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/sacc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/jhawthorn/fzy
COMMENT=	Console gopher client
LICENSE=	isc

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}/man1"
MAKE_FLAGS+=	LIBS=${BUILDLINK_LDADD.terminfo:Q}

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
