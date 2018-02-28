# $NetBSD: Makefile,v 1.2 2018/02/28 16:32:56 leot Exp $

DISTNAME=	sacc-v1.00
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/sacc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/sacc
COMMENT=	Console gopher client
LICENSE=	isc

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}/man1"
MAKE_FLAGS+=	LIBS=${BUILDLINK_LDADD.terminfo:Q}

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
